//by yjz
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
#define less hehehehhehe
#define more asdfasdfasdf
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const ll mod=1000000007;
char a[100111],b[100111];
int n;
bool less,more;
ll calless()
{
    ll ans=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]=='?'&&b[i]!='?')ans=ans*(b[i]-'0'+1)%mod;
        else if(a[i]!='?'&&b[i]=='?')ans=ans*('9'-a[i]+1)%mod;
        else if(a[i]=='?'&&b[i]=='?')ans=ans*55%mod;
    }
    return ans;
}
ll calmore()
{
    ll ans=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]=='?'&&b[i]!='?')ans=ans*('9'-b[i]+1)%mod;
        else if(a[i]!='?'&&b[i]=='?')ans=ans*(a[i]-'0'+1)%mod;
        else if(a[i]=='?'&&b[i]=='?')ans=ans*55%mod;
    }
    return ans;
}
ll calequal()
{
    ll ans=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]=='?'&&b[i]=='?')ans=ans*10%mod;
        else if(a[i]!='?'&&b[i]!='?'&&a[i]!=b[i])ans=0;
    }
    return ans;
}
int main()
{
    scanf("%d%s%s",&n,a+1,b+1);
    for(int i=1;i<=n;i++)
    {
        if(a[i]!='?'&&b[i]!='?')
        {
            if(a[i]<b[i])less=1;
            else if(a[i]>b[i])more=1;
        }
    }
    ll res=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]=='?')res=res*10%mod;
        if(b[i]=='?')res=res*10%mod;
    }
    ll ans=1;
    if(less&&more)
        ans=0;
    else if(less)
        ans=calless();
    else if(more)
        ans=calmore();
    else
        ans=(calless()+calmore()-calequal()+mod)%mod;
    cout<<(res-ans+mod)%mod;
    return 0;
}