#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<int> a(n + 1), to(n + 1, 0), ans(n + 1, 0);
    int score = 0;
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
      if (!to[a[i]])
      {
        to[a[i]] = i;
        ans[i] = a[i];
        score++;
      }
    }

    vector<int> unmatched;
    for (int i = 1; i <= n; i++)
      if (!to[i])
        unmatched.push_back(i);

    for (int i = 1; i <= n; i++)
      if (!ans[i])
      {
        ans[i] = unmatched.back();
        to[ans[i]] = i;
        unmatched.pop_back();
      }

    for (int i = 1; i <= n; i++)
      if (ans[i] == i)
      {
        ans[i] = a[i];
        ans[to[a[i]]] = i;
      }

    cout << score << endl;
    for (int i = 1; i <= n; i++)
      cout << ans[i] << " \n"[i == n];
  }
}