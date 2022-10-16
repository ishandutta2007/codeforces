#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
const int xx=2e5+5;
struct node
{
	int p,m;
	bool operator<(const node&w)const{return m<w.m;}
}e[xx];
int main(){
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;i++)
			e[i].m=read(),e[i].p=read();
		sort(e+1,e+n+1);
		int cnt=0;
		multiset<int>s;
		e[0].m=-1e9;
		ll ans=0;
		for(int i=n;i>=1;i--)
		{
			int r=i;
			while(e[r-1].m==e[i].m)r--;
			for(int j=r;j<=i;j++)s.insert(e[j].p);
			while(s.size()&&cnt+(r-1)<e[i].m)cnt++,ans+=*s.begin(),s.erase(s.begin());
			i=r;
		}
		cout<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}