#include <bits/stdc++.h>
using namespace std;

int main()
{
  int q;
  cin >> q;
  while (q--)
  {
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for (auto c : s)
      for (auto cc : t)
        ans |= c == cc;
    cout << (ans ? "YES" : "NO") << endl;
  }
}