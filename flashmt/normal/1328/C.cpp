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
    string s;
    cin >> n >> s;
    vector<int> a, b;
    int isEqual = 1;
    for (char c : s)
    {
      int x = 0, y = 0;
      if (!isEqual) y = c - '0';
      else if (c == '1')
      {
        x = 1;
        isEqual = 0;
      }
      else x = y = (c - '0') / 2;
      a.push_back(x);
      b.push_back(y);
    }

    for (int x : a)
      cout << x;
    cout << '\n';
    for (int x : b)
      cout << x;
    cout << '\n';
  }
}