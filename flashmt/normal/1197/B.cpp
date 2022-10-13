#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  cin >> n;
  deque<int> q;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    q.push_back(x);
  }

  for (int i = 1; i <= n; i++)
    if (q.front() == i) q.pop_front();
    else if (q.back() == i) q.pop_back();
    else
    {
      cout << "NO" << endl;
      return 0;
    }

  cout << "YES" << endl;
}