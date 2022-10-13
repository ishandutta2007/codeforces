#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  string s;
  cin >> s;
  int n = s.size(), a = 0;
  for (auto c : s)
    a += c == 'a';
  cout << min(n, (a * 2 - 1)) << endl;
}