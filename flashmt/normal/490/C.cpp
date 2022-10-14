#include <bits/stdc++.h>
using namespace std;

string s;
int a, b, modA[1000100], n;

int main()
{
  ios::sync_with_stdio(0);
  cin >> s >> a >> b;
  n = s.size();
  modA[0] = (s[0] - '0') % a;
  for (int i = 1; i < n; i++)
    modA[i] = (modA[i - 1] * 10 + s[i] - '0') % a;
  
  int modB = 0, power = 1;
  for (int i = n - 1; i; i--)
  {
    modB = (modB + power * (s[i] - '0')) % b;
    if (s[i] > '0')
    {
      if (!modB && !modA[i - 1])
      {
        cout << "YES" << endl;
        cout << s.substr(0, i) << endl;
        cout << s.substr(i, n - i) << endl;
        return 0;
      }
    }
    power = power * 10 % b;
  }
  
  cout << "NO" << endl;
}