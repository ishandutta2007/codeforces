#include<bits/stdc++.h>
#define ll long long
#define dd double
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
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=3e5+5;
namespace Main
// 
//:: 
{
	int n,a[xx];
	void solve()
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		multiset<int>s1,s2;
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			int op=3;
			int g1=s1.size()?a[i]-*s1.begin():-1e9;
			int g2=s2.size()?a[i]-*s2.begin():-1e9;
			if(max(g1,g2)>=0)
			{
				if(g1>g2)op=1;
				else op=2;
			}
			if(op==1)
			{
				s2.insert(a[i]);
				ans+=a[i]-*s1.begin();
				s1.erase(s1.begin());
			}
			else if(op==2)
			{
				ans+=a[i]-*s2.begin();
//				cout<<a[i]<<" sdasd "<<*s2.begin()<<"!!\n";
				s1.insert(*s2.begin());
				s2.erase(s2.begin());
				s2.insert(a[i]);
			}
			else s1.insert(a[i]);
//			cout<<i<<" "<<ans<<"\n";
		}
//		for(auto it:s2)cout<<it<<" ";puts("");
		cout<<ans<<"\n";
	}
}
signed main(){
	Main::solve();
	pc('1',1);
	return 0;
}