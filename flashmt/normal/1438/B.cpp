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
    string ans = "NO";
    set<int> s;
    while (n--)
    {
      int x;
      cin >> x;
      if (s.count(x))
        ans = "YES";
      s.insert(x);
    }

    cout << ans << endl;
  }
}