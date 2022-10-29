#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long hell=1e9+7;
const long N = 1e6+2;
long t[2*N]={0};
long n=N;
void modify(long p, long value)
{for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = (t[p] + t[p^1])%hell;}
long query(long l, long r)
{
  long res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1)
  {
    if (l&1) res=(res+t[l++])%hell;
    if (r&1) res=(res+t[--r])%hell;
  }
  return res;
}
long a[100005],i,ans=0,d;
int main()
{
    io
    long n;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=n-1;i>=0;i--)
    {
        d=a[i]*(query(a[i],1e6+1)+1);
        modify(a[i],d);
    }
    for(i=0;i<=1e6;++i)
    ans=(ans+query(i,i+1))%hell;
    cout<<ans;
    return 0;
}