#include<bits/stdc++.h>
using namespace std;
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define int long long
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
const int N=1e6+10;
int n,m,k,a[N],s[N],ma;
main()
{
    ios_base::sync_with_stdio(false);
    //freopen("a.inp","r",stdin);
    cin>>n>>m>>k;
    forinc(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    cout<<(m/(k+1))*(k*a[n]+a[n-1])+(m%(k+1))*a[n];
}