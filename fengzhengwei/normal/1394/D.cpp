#include<bits/stdc++.h>
#define ll long long
#define dd double
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
	pc(x%10+'0',0);
}
void wts(int x,char op)
{
	if(x<0)x=-x,pc('-',0);
	wt(x),pc(op,0);
}
const int xx=2e5+5;
int n,t[xx],H[xx];
struct nod{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}
ll f[xx][2];//01 
struct pr{ll x,y;bool operator<(const pr&a){return y-x>a.y-a.x;}};
// 
void dfs(int x,int y)
{
//	cout<<x<<" "<<y<<"Asd\n";
	vector<pr>v;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x),v.push_back({f[e[i].to][0],f[e[i].to][1]});
	}
	ll cs=0,num1=0,num2=0;
	//1 
	sort(v.begin(),v.end());
	if(x==1)
	{
		cs=0,num1=v.size(),num2=0;
		for(auto it:v)cs+=it.x;
		for(auto it:v)
		{
			f[x][0]=max(f[x][0],cs+min(num1,num2)*t[x]);
			cs+=it.y-it.x,num1--,num2++;
		}
		f[x][0]=max(f[x][0],cs+min(num1,num2)*t[x]);
	}
	else 
	{
		// 
		//num1num2 
		if(H[x]<=H[y])
		{
			cs=0,num1=v.size(),num2=1;
			for(auto it:v)cs+=it.x;
			for(auto it:v)
			{
				f[x][0]=max(f[x][0],cs+min(num1,num2)*t[x]);
				cs+=it.y-it.x,num1--,num2++;
			}
			f[x][0]=max(f[x][0],cs+min(num1,num2)*t[x]);
		}
		if(H[x]>=H[y])
		{
			cs=0,num1=v.size()+1,num2=0;
			for(auto it:v)cs+=it.x;
			for(auto it:v)
			{
				f[x][1]=max(f[x][1],cs+min(num1,num2)*t[x]);
				cs+=it.y-it.x,num1--,num2++;
			}
			f[x][1]=max(f[x][1],cs+min(num1,num2)*t[x]);
		}
	}
}
signed main(){
	for(int i=0;i<xx;i++)for(int j=0;j<2;j++)f[i][j]=-4e12;// 
//	memset(f,-0x3f,sizeof(f));
	n=read();
	for(int i=1;i<=n;i++)t[i]=read();
	for(int i=1;i<=n;i++)H[i]=read();
	ll res=0;
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
		res+=t[a],res+=t[b];
	}
//	cout<<res<<"\n";
	dfs(1,0);
	cout<<res-f[1][0]<<"\n";
	pc('1',1);
	return 0;
}