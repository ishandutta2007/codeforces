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
    vector<int> a(10);
    while (n--)
    {
      int b, d;
      cin >> b >> d;
      d--;
      a[d] = max(a[d], b);
    }

    if (find(begin(a), end(a), 0) != end(a)) cout << "MOREPROBLEMS" << endl;
    else cout << accumulate(begin(a), end(a), 0) << endl;
  }
}