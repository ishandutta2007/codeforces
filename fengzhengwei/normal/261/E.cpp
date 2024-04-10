#include<bits/stdc++.h>
#define ll long long
#define dd long double
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
//map<int,int>mp;
//struct nod
//{
//	int a,b,c;
//};
//queue<nod>q;
//const int xx=105;
const int xx=2944730;
int v[xx+1],tt;
int prim[105],vis[105];
int cnt=0;
void pre(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])prim[++cnt]=i;
		for(int j=1;j<=cnt;j++)
		{
			if(i*prim[j]>n)break;
			vis[i*prim[j]]=1;
			if(i%prim[j]==0)break;
		}
	}
}
void dfs(int x,ll y)
{
	if(x==cnt+1)return v[tt++]=y,void();
	while(1)
	{
		dfs(x+1,y);
		y*=prim[x];
		if(y>1e9)break;
	}
}
//2944730
unsigned char ans[xx+5];
unsigned char f[xx+5];
int main(){
	for(int i=0;i<xx;i++)f[i]=ans[i]=150;
//	memset(f,0xff,sizeof(f));
//	memset(ans,0xff,sizeof(ans));
	//a 
//	cerr<<(int)f[0]<<"\n";
//	cout<<sizeof(f)/1024/1024<<"\n";
	pre(100);
	dfs(1,1);
	sort(v,v+xx);
	f[0]=0;
	for(int i=1;i<100;i++)
	{
		for(int j=0;j<xx;j++)
			ans[j]=min(ans[j],f[j]),f[j]++;
		int ps=0;
		for(int j=0;j<xx;j++)
		{
			while(v[ps]<v[j]/i)ps++;
			if(i*v[ps]==v[j])f[j]=min(f[j],(unsigned char)(f[ps]+1));
		}
	}
//	for(int j=0;j<xx;j++)cout<<j<<" "<<v[j]<<" "<<(int)f[j]<<"!\n";
	int l=read(),r=read(),p=read();
	int re=0;
	for(int j=0;j<xx;j++)if(ans[j]<=p&&l<=v[j]&&v[j]<=r)re++;
	cout<<re<<"\n";
	// 
//	for(auto it:v)cout<<it<<" ";
//	puts("");
//	cout<<v.size()<<"!\n";
//	q.push({1,0,0});
//	while(!q.empty())
//	{
//		nod w=q.front();
//		if(mp.find(w.a)==mp.end())mp[w.a]=w.c;
//		q.pop();
//		if(w.c==23)break;
//		q.push({w.a,w.b+1,w.c+1});
//		q.push({w.a*w.b,w.b,w.c+1});
//	}
//	for(int i=1;i<=100;i++)
//	{
//		cout<<i<<' ';
//		if(mp.find(i)==mp.end())cout<<-1<<"\n";
//		else cout<<mp[i]<<"\n";
//	}
	pc('1',1);
	return 0;
}