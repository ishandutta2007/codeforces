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
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=4e5+5;
struct nod{int next,to,id,col;}e[xx<<1];
int cnt=1,cr[xx<<1],h[xx],cur[xx];
void add(int x,int y,int z){cnt++;e[cnt]={h[x],y,z,1+(cnt&1)};h[x]=cnt;}
int d[xx],col[xx],vis[xx];
void run(int x)
{
//	cout<<x<<"!!\n";
	vis[x]++;
	for(int &i=cur[x];i;i=e[i].next)
	{
		if(!cr[i])
		{
			cr[i]=cr[i^1]=1,col[e[i].id]=e[i].col,run(e[i].to);
//			cout<<x<<" "<<e[i].to<<" "<<e[i].id<<" "<<col[e[i].id]<<"!!\n";
		}
		
	}
}
int main(){
	int n=read();
	for(int i=1;i<=n;i++)
	{
		int a=read(),b=read();
		add(a,b+2e5,i),add(b+2e5,a,i);
		d[a]++,d[b+(int)2e5]++;
	}
	for(int i=1;i<xx;i++)if(d[i]&1)add(i,0,0),add(0,i,0);
//	,puts("ASD");
	for(int i=0;i<xx;i++)cur[i]=h[i];
//	run(1);exit(0);
	for(int i=0;i<xx;i++)if(!vis[i])run(i);
	for(int i=1;i<=n;i++)
	{
		if(col[i]==1)cout<<"b";
		else cout<<"r";
	}
	
	pc('1',1);
	return 0;
}