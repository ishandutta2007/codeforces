#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int N,x,y;string a;ll ans;
int main()
{
	cin>>a>>x>>y;N=a.length();a=" "+a;if(x>y){swap(x,y);For(i,1,N)if(a[i]!='?')a[i]='0'+'1'-a[i];}
	int cnt0=0,cnt1=0;For(i,1,N)a[i]=='0'||a[i]=='?'?ans+=1ll*cnt1*y,cnt0++:(ans+=1ll*cnt0*x,cnt1++);
	ll sum=ans;int tot0=0,tot1=0;FOR(i,N,1)if(a[i]!='?')a[i]=='0'?tot0++:tot1++;else sum-=1ll*(cnt1-tot1)*y+1ll*tot1*x,sum+=1ll*1ll*(cnt0-tot0-1)*x+1ll*tot0*y,ans=min(ans,sum),cnt0--,cnt1++,tot1++;cout<<ans<<endl;return 0;
}