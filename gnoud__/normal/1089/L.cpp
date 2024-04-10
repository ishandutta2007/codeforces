#include<bits/stdc++.h>
using namespace std;
inline long long in()
{
    long long x=0;int c=getchar(),n=0;
    for(;!isdigit(c);c=getchar()) n=(c=='-');
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    return n?-x:x;
}
#define ll long long
#define FOR(i,a,b) for(int i(a);i<=b;i++)
#define ROF(i,a,b) for(int i(b);a<=i;i--)
#define VEC(i,a) for(auto&i:a)
#define rr(x) " "<<#x<<'='<<x<<" "
#define mt make_tuple
#define t0(a) get<0>(a)
#define t1(a) get<1>(a)
#define pb push_back
const int N=1e5+5;
int n,k;
int a[N];
ll b[N];
int Cnt;
tuple<ll,int> f[N];
vector<ll> v;
ll res;
main()
{
    //freopen("42.inp","r",stdin);
    n=in(),k=in();memset(f,-128,sizeof(f));
    FOR(i,1,n) a[i]=in();
    FOR(i,1,n) b[i]=in();
    FOR(i,1,n)
    {
        int x=a[i];
        f[x]=max(f[x],mt(b[i],i));
    }
   // FOR(i,1,k) cout<<rr(i) rr(t0(f[i])) rr(t1(f[i]))"\n";
    FOR(i,1,n)
    {
        int x=a[i];
        if(t1(f[x])!=i) v.pb(b[i]);
        else Cnt++;
    }
    sort(v.begin(),v.end());
    for(int i=0,j=Cnt+1;j<=k;j++,i++) res+=v[i];
    cout<<res;
}