#include <bits/stdc++.h>
using namespace std;

struct Query
{
  int t, x, p;
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[200200], Q;
  Query q[200200];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  cin >> Q;
  for (int i = 0; i < Q; i++)
  {
    cin >> q[i].t;
    if (q[i].t == 1) cin >> q[i].p >> q[i].x;
    else cin >> q[i].x;
    q[i].p--;
  }

  vector<int> payoffs, done(n, 0);
  for (int i = Q - 1; i >= 0; i--)
    if (q[i].t == 1)
    {
      if (!done[q[i].p])
      {
        done[q[i].p] = 1;
        a[q[i].p] = q[i].x;
        if (!payoffs.empty())
          a[q[i].p] = max(a[q[i].p], payoffs.back());
      }
    }
    else
    {
      if (payoffs.empty() || q[i].x > payoffs.back())
        payoffs.push_back(q[i].x);
    }

  for (int i = 0; i < n; i++)
  {
    if (!done[i] && !payoffs.empty())
      a[i] = max(a[i], payoffs.back());
    cout << a[i] << " \n"[i == n - 1];
  }
}