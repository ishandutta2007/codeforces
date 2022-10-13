#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
  int n, sum = 0;
  string s;
  cin >> n >> s;
  for (char c : s)
    sum += c - '0';
  
  if (sum * 2 != n) cout << 1 << endl << s << endl;
  else cout << 2 << endl << s[0] << ' ' << s.substr(1, n - 1) << endl;
}