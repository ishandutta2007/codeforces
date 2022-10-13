#include <bits/stdc++.h>
using namespace std;

int k;

char bestChar(char c)
{
  return c == 'a' || c - 'a' == k - 1 ? 'a' : c - 1;
}

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
    cin >> n >> k >> s;
    for (int i = 0; i < n;)
      if (i && i + 1 < n && s[i + 1] < s[i] && s[i + 1] < s[i - 1])
      {
        swap(s[i], s[i + 1]);
        swap(s[i], s[i - 1]);
        i += 2;
      }
      else if (i && s[i] < s[i - 1])
      {
        swap(s[i], s[i - 1]);
        i++;
      }
      else if (i + 2 < n && s[i + 2] < min(bestChar(s[i]), bestChar(s[i + 1])))
      {
        s[i] = bestChar(s[i]);
        i++;
      }
      else if (i + 1 < n && bestChar(s[i + 1]) < bestChar(s[i]))
      {
        if (s[i + 1] == 'a')
          s[i] = bestChar(s[i]);
        swap(s[i], s[i + 1]);
        s[i] = bestChar(s[i]);
        i += 2;
      }
      else
      {
        s[i] = bestChar(s[i]);
        i++;
      }

    cout << s << endl;
  }
}