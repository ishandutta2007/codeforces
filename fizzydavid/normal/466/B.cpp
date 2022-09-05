/*
while(true)rp++;
*/
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
const int INF=1<<29;
const long long LINF=1ll<<62;
ll n,a,b,ans,ansx,ansy;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>a>>b;
    n=n*6;
    if(a*b>=n)
    {
        ans=a*b,ansx=a,ansy=b;
        cout<<ans<<endl<<ansx<<" "<<ansy;
        return 0;
    }else ans=LINF;
    for(ll i=a;i*i<=n;i++)
    {
        ll b1=0;
        if(n%i==0)b1=max(b,n/i);else b1=max(b,n/i+1);
//      cout<<i<<" "<<b1<<endl;
        if(i*b1<ans)ans=i*b1,ansx=i,ansy=b1;
    }
    for(ll i=b;i*i<=n;i++)
    {
        ll b1=0;
        if(n%i==0)b1=max(a,n/i);else b1=max(a,n/i+1);
        if(i*b1<ans)ans=i*b1,ansx=b1,ansy=i;
    }
    cout<<ans<<endl<<ansx<<" "<<ansy;
    return 0;
}