#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	((op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf));
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(c,0);
}
int n,m;
const int xx=3e5+5;
ll c[xx],d[xx];
signed main(){
	n=read(),m=read();
	multiset<ll>s;//sgm c-a + mx d  
	for(int i=1;i<=n;i++)d[i]=read(),c[i]=m-read();
	for(int i=1;i<=n;i++)c[i]+=c[i-1];
	stack<pair<ll,ll> >stk;
	ll ans=0;
//	d[0]=d[1];
	for(int i=1;i<=n;i++)
	{
		ll mn=1e18;
		ll V=(d[i]-d[i-1])*(d[i]-d[i-1]);
		while(stk.size()&&stk.top().second<V)
		{
			mn=min(mn,stk.top().first-stk.top().second);
			s.erase(s.find(stk.top().first));
			stk.pop();
		}
		if(mn!=1e18)
		{
			stk.push(make_pair(mn+V,V));
			s.insert(mn+V);
		}
		stk.push(make_pair(c[i-1],0));
		s.insert(c[i-1]);
		ans=max(ans,c[i]-*s.begin());
	}
	cout<<ans<<"\n";
	pc('-',1);
	return 0;
}