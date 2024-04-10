#include <bits/stdc++.h>
using namespace std;

int n, b[1010], flag[1010];
vector<int> a;

void solveAllOdd()
{
  unordered_map<int, int> m[14];
  int curN = min(n, 26), mask1 = -1, mask2 = -1;
  for (int mask = 1; mask < 1 << curN; mask++)
  {
    int bit = __builtin_popcount(mask);
    if (bit * 2 > curN)
      continue;
    int sum = 0;
    for (int i = 0; i < curN; i++)
      if (mask >> i & 1)
        sum += b[i];

    if (m[bit].count(sum))
    {
      mask1 = m[bit][sum];
      mask2 = mask;
      break;
    }
    m[bit][sum] = mask;
  }

  if (mask1 < 0)
  {
    cout << "NO" << endl;
    exit(0);
  }

  int common = mask1 & mask2;
  mask1 ^= common;
  mask2 ^= common;
  int sz = __builtin_popcount(mask1) * 2;
  vector<int> cycleB(sz * 2);
  for (int i = 0, evenId = 0, oddId = 1; i < curN; i++)
    if (mask1 >> i & 1)
    {
      cycleB[evenId] = b[i];
      flag[i] = 1;
      evenId += 2;
    }
    else if (mask2 >> i & 1)
    {
      cycleB[oddId] = b[i];
      flag[i] = 1;
      oddId += 2;
    }

  a = {0};
  for (int i = 1; i < sz; i++)
    a.push_back({cycleB[i] - a.back()});
  assert(a[0] + a.back() == cycleB[0]);
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> b[i];

  if (n == 2)
  {
    if (b[0] != b[1]) cout << "NO" << endl;
    else cout << "YES" << endl << 0 << ' ' << b[0] << endl;
    return 0;
  }

  sort(b, b + n);
  for (int i = 1; i < n; i++)
    if (b[i] == b[i - 1])
    {
      cout << "YES" << endl;
      cout << 0 << ' ';
      for (int j = 0; j < n; j++)
        if (j != i)
          cout << b[j] << ' ';
      return 0;
    }

  vector<int> id[2];
  for (int i = 0; i < n; i++)
    id[b[i] % 2].push_back(i);

  auto calcTriple = [&](int x, int y, int z)
  {
    flag[x] = flag[y] = flag[z] = 1;
    int sum = (b[x] + b[y] + b[z]) / 2;
    a.push_back(sum - b[x]);
    a.push_back(sum - b[y]);
    a.push_back(sum - b[z]);
  };

  if (size(id[0]) >= 3) calcTriple(id[0][0], id[0][1], id[0][2]);
  else if (size(id[1]) >= 2 && size(id[0])) calcTriple(id[1][0], id[1][1], id[0][0]);
  else solveAllOdd();

  for (int i = 0; i < n; i++)
    if (!flag[i])
      a.push_back(b[i] - a[0]);

  cout << "YES" << endl;
  for (int x : a)
    cout << x << ' ';
}