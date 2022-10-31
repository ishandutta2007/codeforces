#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline bool ispr(ll x)
{
  for(ll i = 2; i * i <= x; i++)
    if(x % i == 0) return 0;
  return 1;
}

int main()
{
  int tc;scanf("%d", &tc);while(tc--)
  {
    int n;scanf("%d", &n);
    n++;
    ll ubp = n+1, lbp = n;
    while(!ispr(ubp)) ubp++;
    while(!ispr(lbp)) lbp--;
    // 1/2 - 1/lbp + ( n - lbp ) * ( 1 / ubp*lbp );
    ll num = 2 * lbp * ubp;
    ll den = lbp * ubp - 2*ubp + 2*(n-lbp);
    ll g = __gcd(num, den);
    num /= g, den /= g;
    cout << den << '/' << num << '\n';
  }
}