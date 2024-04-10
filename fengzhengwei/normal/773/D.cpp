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
const int xx=2e3+5;
int n;
ll v[xx][xx],f[xx];
int vis[xx];
struct nod
{
	int x;ll v;
	bool operator<(const nod&w)const{return v>w.v;}
};
int main(){
	n=read();
	ll mn=1e9;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			v[i][j]=v[j][i]=read(),mn=min(mn,v[i][j]);
	memset(f,0x3f,sizeof(f));
	ll re=1ll*mn*(n-1);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			f[i]=min(f[i],v[i][j]*2-mn-mn);
			f[j]=min(f[j],v[i][j]*2-mn-mn);
		}
	priority_queue<nod>q;
	for(int i=1;i<=n;i++)q.push({i,f[i]});
	// 
	//caon^2log 
	while(!q.empty())
	{
		int x=q.top().x;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=1;i<=n;i++)
		{
			if(i==x)continue;
			if(f[i]>f[x]+v[i][x]-mn)
			{
				f[i]=f[x]+v[i][x]-mn;
				q.push({i,f[i]});
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<f[i]+re<<"\n";
	pc('1',1);
	return 0;
}