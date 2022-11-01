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

#define int ll
const int N=1e5+5;
ll n,a[10];
ll res,SUM;
ll CAL(ll x)
{
    return x/SUM+(x%SUM!=0);
}
ll sum(int l,int r)
{
    int sum=0;
    FOR(i,l,r) sum+=a[i];
    return sum;
}
void SOLVE()
{
    n=in();res=1e15;SUM=0;
    FOR(i,1,7) a[i]=in(),SUM+=a[i];
    FOR(i,1,7) FOR(j,i,7) if(n<=sum(i,j)) res=min(res,(ll)j-i+1);
    FOR(i,1,7) FOR(j,1,7)
    {
        int L=sum(i,7),R=sum(1,j);
        res=min(res,7-i+1+j-1+1+7*CAL(n-L-R));
    }
    cout<<res<<"\n";
}
main()
{
  //  freopen("42.inp","r",stdin);
    int test=in();
    FOR(sgjjh,1,test)
    {
        SOLVE();
    }
}