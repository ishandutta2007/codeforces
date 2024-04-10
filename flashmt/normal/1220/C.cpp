#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  int flag[256] = {0};
  cin >> s;
  for (char c : s)
  {
    int found = 0;
    for (char i = 'a'; i < c; i++)
      if (flag[i])
        found = 1;
    cout << (found ? "Ann\n" : "Mike\n");
    flag[c] = 1;
  }
}