#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;

  vector<int> f(1 << n), rank(1 << n);
  for (int i = 0; i < 1 << n; i++)
  {
    f[i] = i;
    rank[i] = s[i] - 'a';
  }
  sort(begin(f), end(f), [&](int u, int v) { return rank[u] < rank[v]; });

  for (int i = 0; i < n; i++)
  {
    auto comp = [&](int u, int v)
    {
      int uu = u ^ 1 << i, vv = v ^ 1 << i;
      return rank[u] < rank[v] || (rank[u] == rank[v] && rank[uu] < rank[vv]);
    };
    sort(begin(f), end(f), comp);

    vector<int> newRank(1 << n);
    int numRank = 1;
    newRank[f[0]] = 0;
    for (int j = 1; j < 1 << n; j++)
    {
      if (rank[f[j - 1]] != rank[f[j]] || rank[f[j - 1] ^ 1 << i] != rank[f[j] ^ 1 << i])
        numRank++;
      newRank[f[j]] = numRank - 1;
    }
    swap(rank, newRank);
  }

  for (int i = 0; i < 1 << n; i++)
    cout << s[i ^ f[0]];
  cout << endl;
}