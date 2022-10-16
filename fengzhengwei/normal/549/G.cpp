#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=2e5+5;
int n,ans[xx];
multiset<int>s;
signed main(){
	n=read();
	for(int i=1;i<=n;i++)s.insert(read()-(n-i));
	int dlt=0;
	for(int i=n;i>=1;i--)
	{
		ans[i]=*--s.end()+dlt;
		s.erase(--s.end());
		dlt++;
	}
	for(int i=1;i<n;i++)if(ans[i]>ans[i+1])puts(":("),exit(0);
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";puts("");
	return 0;
}