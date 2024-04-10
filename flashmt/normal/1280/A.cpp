#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000010;
const int BASE = 1e9 + 7;

int a[MAX + 5];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    int x;
    string s;
    cin >> x >> s;

    int n = s.size();
    for (int i = 0; i < n; i++)
      a[i] = s[i] - '0';

    int exceed = 0;
    long long len = n;
    for (int i = 1; i <= x; i++)
      if (i < len || exceed)
      {
        long long suffix = (len - i + BASE) % BASE;
        long long gain = suffix * (a[i - 1] - 1);
        len += gain;
        if (!exceed)
        {
          if (len > MAX)
          {
            gain = MAX - n;
            exceed = 1;
          }
          for (int j = n; j < n + gain; j++)
            a[j] = a[j - suffix];
          n += gain;
        }
        len %= BASE;
      }

    cout << len << '\n';
  }
}