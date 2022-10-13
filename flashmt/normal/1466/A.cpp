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
    int n, x[55];
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
      cin >> x[i];
      for (int j = 0; j < i; j++)
        s.insert(x[i] - x[j]);
    }
    cout << s.size() << endl;
  }
}