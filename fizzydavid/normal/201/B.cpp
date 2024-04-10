//source:201B
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const int INF=1<<28;
const long long LINF=1ll<<61;
int n,m;
ll a[1011][1011],row[1011],col[1011];
ll mysqr(ll x)
{
    return x*x;
}
ll dis(ll x,ll x2)
{
    return mysqr(x2*4-2-x*4);
}
ll cal1(ll x)
{
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        ans+=row[i]*dis(x,i);
//      cout<<"col["<<i<<"]="<<col[i]<<" dis("<<x<<","<<i<<")="<<dis(x,i)<<" value="<<col[i]*dis(x,i)<<endl;;
    }
    return ans;
}
ll cal2(ll x)
{
    ll ans=0;
    for(ll i=1;i<=m;i++)
    {
        ans+=col[i]*dis(x,i);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    ll ansx,ansy;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){cin>>a[i][j];row[i]+=a[i][j];col[j]+=a[i][j];}
    ll ans1=LINF,ans2=LINF;
    for(ll i=0;i<=n;i++)if(cal1(i)<ans1)ansx=i,ans1=cal1(i);
    for(ll i=0;i<=m;i++)if(cal2(i)<ans2)ansy=i,ans2=cal2(i);
    cout<<ans1+ans2<<endl<<ansx<<" "<<ansy;
    return 0;
}