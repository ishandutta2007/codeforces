#include <iostream>
#include <cstdio>

#include <vector>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)
using vi = vector<int>;
using vl = vector<ll>;
#define pb push_back
#define bk back()

bool mn(ll& a, const ll& b) {return a==-1||b<a?a=b,1:0;}

int N, C, D, R;
vi t[2];
vl d[2];
int a[2], m[2];
void dodp(bool c, int x)
{
  ll p = 0LL;
  d[c].pb(tl(a[0]+a[1])*D);
  for(int i = a[!c];i >= m[c];i--)
  {
    if(i<a[!c])
      p += (x-t[!c][i])*C;
    if(a[c])
    {
      if(m[c]<i)
        mn(d[c].bk, d[!c][m[c]] + p + (x-t[!c][m[c]])*C + tl(i-m[c]-1)*D);
      if(i<a[!c])
        mn(d[c].bk, d[!c][i] + p);
    }
    mn(d[c].bk, p+tl(i+a[c])*D);
  }
  m[c] = a[!c];
  t[c].pb(x);
  a[c]++;
}
int x;
char w;
int main(void)
{
  scanf("%d%d%d", &N, &C, &D);
  R = D/C;
  for(int i = 0;i < N;i++)
  {
    scanf("%d %c", &x, &w);
    dodp(w=='W', x);
    //printf("%lld\n", d[w=='W'].bk);
  }
  scanf("%d", &x);
  dodp(w!='W', x);
  printf("%lld\n", d[w!='W'].bk);
  return 0;
}