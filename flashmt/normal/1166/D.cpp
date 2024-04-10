#include <bits/stdc++.h>
using namespace std;

void solve(long long a, long long b, long long m)
{
  for (int length = 2; length <= 48; length++)
    if (a + 1 <= b >> length - 2 && (b + (1LL << length - 2) - 1) >> length - 2 <= a + m)
    {
      long long sum = b - (a + 1 << length - 2);
      vector <long long> allR;
      for (int i = length - 3; i >= -1; i--)
      {
        long long r = min(m - 1, sum >> max(i, 0));
        allR.push_back(r + 1);
        sum -= r << max(i, 0);
      }

      cout << length << ' ' << a;
      sum = a;
      for (auto r : allR)
      {
        cout << ' ' << sum + r;
        sum += sum + r; 
      }
      cout << endl;
      return;
    }

  cout << -1 << endl;
}

int main()
{
  int q;
  long long a, b, m;
  cin >> q;
  while (q--)
  {
    cin >> a >> b >> m;
    if (a == b) cout << "1 " << a << endl;
    else solve(a, b, m);
  }
}