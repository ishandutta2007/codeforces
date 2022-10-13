#include <bits/stdc++.h>
using namespace std;
const long long oo = (long long)1e4;

long long n, k;
vector < pair <int,int> > l, r;

int length(int x)
{
  return x < 10 ? 1 : length(x / 10) + 1;
}

pair <int,int> checkWavy(int x)
{
  if (x < 10) return make_pair(1, 0);
  int digits[8] = {x % 10, x / 10 % 10}, len = 2, sign = digits[1] > digits[0];
  if (digits[1] == digits[0]) return make_pair(0, 0);
  x /= 100;
  while (x)
  {
    digits[len] = x % 10;
    x /= 10;
    if (digits[len] == digits[len - 1]) return make_pair(0, 0);
    int newSign = digits[len] > digits[len - 1];
    if (newSign == sign) return make_pair(0, 0);
    sign = newSign;
    len++;
  }
  
  if (len < 6) return make_pair(1, 0);
  if (len == 7) return make_pair(1, 1);
  return make_pair(1, sign);
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n >> k;
  
  for (int i = 1; i < int(1e7); i++)
  {
    pair <int,int> u = checkWavy(i);
    if (!u.first) continue;
    
    if (i % n == 0)
      if (!--k)
      {
        cout << i << endl;
        return 0;
      }
      
    l.push_back(make_pair(i, i % n));
    if (u.second) r.push_back(make_pair(i % n, i));
      
  }
  
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  
  for (int i = 0; i < int(l.size()); i++)
  {
    if ((n - 1LL * l[i].second * int(1e7) % n) % n > int(1e7)) continue;
    int mod = (n - 1LL * l[i].second * int(1e7) % n) % n;
    int x = l[i].first, lastDigit = x % 10;
    
    int from = lower_bound(r.begin(), r.end(), make_pair(mod, 0)) - r.begin();
    int to = lower_bound(r.begin(), r.end(), make_pair(mod + 1, 0)) - r.begin();
    if (from == to) continue;
    
    for (int digit = 0; digit < 10 && from < to; digit++)
    {
      int bound = lower_bound(r.begin() + from, r.begin() + to, make_pair(mod, (digit + 1) * int(1e6))) - r.begin();
      
      if (digit < lastDigit)
      {
        if (x < 10 || x / 10 % 10 < lastDigit)
        {
          int low = (digit * 10 + digit + 1) * int(1e5);
          int idLow = lower_bound(r.begin() + from, r.begin() + bound, make_pair(mod, low)) - r.begin();
          if (bound - idLow >= k)
          {
            cout << x;
            for (int q = length(r[from + k - 1].second); q < 7; q++) cout << 0;
            cout << r[idLow + k - 1].second << endl;
            return 0;
          }
          else k -= bound - idLow;
        }
      }
      
      if (digit > lastDigit)
      {
        if (x < 10 || x / 10 % 10 > lastDigit)
        {
          int high = (digit * 10 + digit) * int(1e5);
          int idHigh = lower_bound(r.begin() + from, r.begin() + bound, make_pair(mod, high)) - r.begin();
          if (idHigh - from >= k)
          {
            cout << x;
            for (int q = length(r[from + k - 1].second); q < 7; q++) cout << 0;
            cout << r[from + k - 1].second << endl;
            return 0;
          }
          else k -= idHigh - from;
        }
      }
      
      from = bound;
    }
  }
  
  cout << -1 << endl;
}