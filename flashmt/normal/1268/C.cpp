#include <bits/stdc++.h>
using namespace std;

int n, p[200200], id[200200];
long long tree[200200], tree2[200200], numSmaller[200200];

void add(long long tree[], int x, int v)
{
  for (int i = x; i <= n; i += i & -i)
    tree[i] += v;
}

long long get(long long tree[], int x)
{
  long long res = 0;
  for (int i = x; i; i -= i & -i)
    res += tree[i];
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> p[i];
    id[p[i]] = i;
  }

  for (int i = n; i; i--)
  {
    numSmaller[p[i]] = get(tree, p[i]);
    add(tree, p[i], 1);
  }
  memset(tree, 0, sizeof tree);

  cout << 0 << ' ';
  set<int> ids;
  ids.insert(id[1]);
  int rank = 1, median = id[1];
  add(tree, id[1], 1);
  add(tree2, id[1], id[1]);

  for (int x = 2; x <= n; x++)
  {
    int i = id[x];
    ids.insert(i);
    if (i < median)
      rank++;

    auto it = ids.find(median);
    int minRank = x / 2 + 1, maxRank = x / 2 + 1;
    if (x % 2 == 0)
      minRank--;
    while (rank < minRank)
    {
      it++;
      rank++;
    }
    while (rank > maxRank)
    {
      it--;
      rank--;
    }

    median = *it;
    add(tree, i, 1);
    add(tree2, i, i);

    int leftCnt = get(tree, median - 1);
    long long leftSum  = get(tree2, median - 1);
    int rightCnt = get(tree, n) - get(tree, median);
    long long rightSum = get(tree2, n) - get(tree2, median);
    long long move = rightSum - 1LL * rightCnt * median;
    move += 1LL * leftCnt * median - leftSum;
    move -= rank * (rank - 1LL) / 2;
    move -= (x - rank) * (x - rank + 1LL) / 2;
    numSmaller[x] += numSmaller[x - 1];
    cout << move + numSmaller[x] << ' ';
  }
}