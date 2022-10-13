#include <bits/stdc++.h>
using namespace std;
const string VOWEL = "AEIOUY";

string s;
double coef[500500], add[500500];

int isVowel(char c)
{
  return VOWEL.find(c) != string::npos;
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> s;
  int n = s.size();
  
  for (int i = 1; i <= n; i++)
  {
    int x = min(i, n + 1 - i);
    add[1] += 1.0 / i;
    add[x + 1] -= 1.0 / i;
    add[n - x + 2] -= 1.0 / i;
  }
  
  for (int i = 1; i <= n; i++)
  {
    add[i] += add[i - 1];
    coef[i] = coef[i - 1] + add[i];
  }
  
  double ans = 0;
  for (int i = 0; i < n; i++)
    if (isVowel(s[i]))
      ans += coef[i + 1];
    
  cout << fixed << setprecision(9) << ans << endl;
}