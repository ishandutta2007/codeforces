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
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=2e4+5;
int n,p;
struct nod
{
	ll a[4005];
	void in(int c,int h){for(int i=4000;i>=c;i--)a[i]=max(a[i],a[i-c]+h);}
	void cls(){memset(a,0,sizeof(a));}
}lin,stk[4005];
int top,pr;
ll qu(const nod&a,const nod&b,int c)
{
	ll ans=0;
	for(int i=0;i<=c;i++)ans=max(ans,a.a[i]+b.a[c-i]);
	return ans;
}
struct node
{
	int c,h,t;
	bool operator<(const node&w)const{return t<w.t;}
}e[xx];
vector<int>er[xx],in[xx];
struct Qu{int id,b;};
vector<Qu>Q[xx];
int ans[xx];
int main(){
	n=read(),p=read();
	for(int i=1;i<=n;i++)e[i].c=read(),e[i].h=read(),e[i].t=read();
	sort(e+1,e+n+1);
	// 
	for(int i=1;i<=n;i++)
		er[e[i].t+p].push_back(i),in[e[i].t].push_back(i);
	int q=read();
	for(int i=1;i<=q;i++)
	{
		int a=read(),b=read();
		Q[a].push_back({i,b});
	}
	int lim=0;
	for(int i=1;i<=20000;i++)
	{
		for(auto it:in[i])
			++lim,++top,lin.in(e[it].c,e[it].h);
		for(auto it:er[i])
		{
			if(pr==0)
			{
				for(int j=lim;j>=lim-top+1;j--)stk[pr+1]=stk[pr],stk[pr+1].in(e[j].c,e[j].h),pr++;
				lin.cls(),top=0;
			}
			--pr;
		}
		for(auto it:Q[i])
			ans[it.id]=qu(stk[pr],lin,it.b);
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
	pc('1',1);
	return 0;
}