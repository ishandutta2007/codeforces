#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;
const int SZ = 320;

struct BlockData
{
  int sumC;
  vector<long long> sumF;

  BlockData() {}
};

int n, k, c[100100];
long long f[100100];
BlockData blocks[SZ];

long long calc(int i)
{
  long long res = 0;
  // calc F from same block
  int sumC = 0, block = i / SZ;
  for (int j = i; j >= block * SZ; j--)
  {
    sumC += c[j];
    if (sumC <= k)
      res += j ? f[j - 1] : 1;
  }
  // calc F from previous blocks
  for (int j = block - 1; j >= 0; j--)
  {
    int need = k - sumC;
    if (need >= -SZ)
      res += blocks[j].sumF[min(need, SZ) + SZ];
    sumC += blocks[j].sumC;
  }
  return res % BASE;
}

void constructBlock(int block)
{
  BlockData &data = blocks[block];
  data.sumC = 0;
  data.sumF = vector<long long>(SZ * 2 + 1, 0);

  for (int i = block * SZ + SZ - 1; i >= block * SZ; i--)
  {
    data.sumC += c[i];
    data.sumF[data.sumC + SZ] += i ? f[i - 1] : 1;
  }

  for (int i = 0; i <= SZ * 2; i++)
  {
    if (i)
      data.sumF[i] += data.sumF[i - 1];
    data.sumF[i] %= BASE;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x;
  cin >> n >> k;
  vector<int> id[100100];
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    c[i] = 1;
    if (!id[x].empty())
    {
      int j = id[x].back();
      c[j] = -1;
      if (id[x].size() >= 2)
      {
        int k = id[x][id[x].size() - 2];
        c[k] = 0;
        if (k / SZ != j / SZ)
          constructBlock(k / SZ);
      }
      if (j / SZ != i / SZ)
        constructBlock(j / SZ);
    }
    id[x].push_back(i);

    f[i] = calc(i);
    // construct sumF if this is the last element of a block
    if (i % SZ == SZ - 1)
      constructBlock(i / SZ);
  }

  cout << f[n - 1] << endl;
}