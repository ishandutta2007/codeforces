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
#define aint(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
const int N=2e5+5;
int x,y,u,v,n;
string s;
int X[N],Y[N];
bool cheq(int m)
{
    int DIV=m/n;
    int MOD=m%n;
    int yy=y+Y[n]*DIV+Y[MOD];
    int xx=x+X[n]*DIV+X[MOD];
    return abs(u-xx)+abs(v-yy)<=m;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("c.inp","r",stdin);
    cin>>x>>y>>u>>v>>n;
    cin>>s;s=" "+s;
    forinc(i,1,n)
    {
        X[i]=X[i-1];
        Y[i]=Y[i-1];
        if(s[i]=='U') Y[i]++;
        if(s[i]=='D') Y[i]--;
        if(s[i]=='L') X[i]--;
        if(s[i]=='R') X[i]++;
    }
    int l=0,r=(1ll<<62)-1,res=-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(cheq(mid)) r=mid-1,res=mid;
        else l=mid+1;
    }
    cout<<res;
}