#include <bits/stdc++.h>
using namespace std;
const int N = 1000100;

int n;
long long k, a[N];
int numNode; // number of current nodes in trie
int curNode[N]; // which node in trie is a[i] currently at
int cnt[N][2], id[N][2];
pair<int, int> pairs[N], newPairs[N]; // pairs of nodes whose xor is current ans

long long countZero(int bit)
{
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; i++)
    cnt[curNode[i]][a[i] >> bit & 1]++;

  long long res = 0;
  for (int i = 0; i < numNode; i++)
    for (int j = 0; j < 2; j++)
      res += 1LL * cnt[pairs[i].first][j] * cnt[pairs[i].second][j];

  return res;
}

void go(int bit, int bitValue)
{
  // Move each a[i] to next bit
  memset(id, -1, sizeof id);
  int numId = 0;
  for (int i = 0; i < n; i++)
  {
    int j = a[i] >> bit & 1;
    if (id[curNode[i]][j] < 0)
      id[curNode[i]][j] = numId++;
    curNode[i] = id[curNode[i]][j];
  }

  // Update pairs
  int newNumNode = 0;
  for (int i = 0; i < numNode; i++)
    for (int j = 0; j < 2; j++)
    {
      int x = id[pairs[i].first][j], y = id[pairs[i].second][j ^ bitValue];
      if (x >= 0 && y >= 0)
        newPairs[newNumNode++] = {x, y};
    }

  numNode = newNumNode;
  copy(newPairs, newPairs + newNumNode, pairs);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i < n; i++)
  {
    int p;
    long long w;
    cin >> p >> w;
    a[i] = a[--p] ^ w;
  }

  numNode = 1;
  long long ans = 0;
  for (int bit = 61; bit >= 0; bit--)
  {
    long long zero = countZero(bit);
    if (k <= zero) go(bit, 0);
    else
    {
      go(bit, 1);
      k -= zero;
      ans |= 1LL << bit;
    }
  }

  cout << ans << endl;
}