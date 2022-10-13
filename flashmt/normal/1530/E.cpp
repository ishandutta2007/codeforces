#include <bits/stdc++.h>
using namespace std;

int cnt[26];

void write(int c)
{
  cout << char(c + 'a');
  cnt[c]--;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    memset(cnt, 0, sizeof cnt);
    string s;
    cin >> s;
    for (char c : s)
      cnt[c - 'a']++;

    int appearOnce = -1, distinct = 0;
    for (int i = 0; i < 26; i++)
      if (cnt[i])
      {
        if (cnt[i] == 1 && appearOnce < 0)
          appearOnce = i;
        distinct++;
      }

    if (distinct == 1) // aaaaa
    {
      cout << s << '\n';
      continue;
    }

    if (appearOnce >= 0) // abbcc..
    {
      write(appearOnce);
    }
    else
    {
      int start = -1;
      for (int i = 0; i < 26; i++)
        if (cnt[i] >= 2)
        {
          start = i;
          break;
        }

      assert(start >= 0);

      write(start);
      int second = -1, rem = 0;
      for (int i = start + 1; i < 26; i++)
        if (cnt[i])
        {
          rem += cnt[i];
          if (second < 0)
            second = i;
        }

      if (cnt[start] <= rem + 1) // aabacad...
      {
        while (cnt[start] > 0)
        {
          write(start);
          for (int i = start + 1; i < 26; i++)
            if (cnt[i])
            {
              write(i);
              break;
            }
        }
      }
      else if (distinct >= 3) // abaaac...
      {
        write(second);
        while (cnt[start] > 0)
          write(start);
        int found = 0;
        for (int i = second + 1; i < 26; i++)
          if (cnt[i])
          {
            write(i);
            found = 1;
            break;
          }
        assert(found);
      }
      else // abbbaaaa
      {
        while (cnt[second] > 0)
          write(second);
      }
    }

    // remaining
    for (int i = 0; i < 26; i++)
      while (cnt[i] > 0)
        write(i);
    cout << '\n';
  }
}