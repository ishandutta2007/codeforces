#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
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
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
const int xx=5e5+5;
int a[xx];
struct nod
{
	int id,v;
	bool operator<(const nod&w)const{return v>w.v;}
}e[xx];
int res[xx];
signed main(){
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;i++)
			a[i]=e[i].v=read(),e[i].id=i;
		sort(e+1,e+n+1);
		int np=1,op=0;
		ll ans=0;
		res[0]=0;
		for(int i=1;i<=n;i++)
		{
			ans+=1ll*2*np*e[i].v;
			if(op==0)
			{
				res[e[i].id]=0+np;
				op=1;
			}
			else 
			{
				op=0;
				res[e[i].id]=0-np;
				np++;
			}
		}
		cout<<ans<<"\n";
		for(int i=0;i<=n;i++)cout<<res[i]<<" \n"[i==n];
	}
	pc('1',1);
	return 0;
}