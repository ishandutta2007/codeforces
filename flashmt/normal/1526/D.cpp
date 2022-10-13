#include <bits/stdc++.h>
using namespace std;
const string C = "ANOT";

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < 4; j++)
        if (s[i] == C[j])
          a[i] = j;

    vector<int> p = {0, 1, 2, 3}, pAns;
    long long ans = -1;
    do
    {
      int cnt[4] = {0};
      long long cost = 0;
      for (int x : a)
      {
        for (int i = p[x] + 1; i < 4; i++)
          cost += cnt[i];
        cnt[p[x]]++;
      }
      if (cost > ans)
      {
        ans = cost;
        pAns = p;
      }
    } while (next_permutation(p.begin(), p.end()));

    vector<int> cnt(4);
    for (int x : a)
      cnt[x]++;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        if (pAns[j] == i)
          for (int k = 0; k < cnt[j]; k++)
            cout << C[j];
    cout << '\n';
  }
}