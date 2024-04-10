#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, cnt[26] = {0};
  string s;
  cin >> n >> s;
  for (char c : s)
    cnt[c - 'a']++;

  for (int i = 0; i < 26; i++)
    if (cnt[i] > 1)
    {
      cout << "Yes" << endl;
      return 0;
    }

  cout << (n == 1 ? "Yes" : "No") << endl;
}