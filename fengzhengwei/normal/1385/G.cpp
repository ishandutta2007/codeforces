#include<bits/stdc++.h>
#define ll long long
#define dd double
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
int t[xx],a[xx],b[xx];
vector<int>v[xx];
int find(int col,int x)
{
	if(v[col][0]==x)return v[col][1];
	return v[col][0];
}
int vis[xx],op[xx];//0 
vector<int>ans,cir;
void findc(int x,int s)
{
	if(vis[x])return;
	vis[x]=1;
	cir.push_back(x);
	op[x]=s;
	if(!s)
	{
		int to=find(a[x],x);
		findc(to,a[to]==a[x]);// 
	}
	else 
	{
		int to=find(b[x],x);
		findc(to,a[to]==b[x]);
	}
}
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	int T=read();
	while(T--)
	{
		int n=read();
		ans.clear();
		memset(t,0,sizeof(t[0])*(n+1));
		memset(vis,0,sizeof(vis[0])*(n+1));
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<=n;i++)a[i]=read(),t[a[i]]++,v[a[i]].push_back(i);
		for(int i=1;i<=n;i++)b[i]=read(),t[b[i]]++,v[b[i]].push_back(i);
		int vs=0;
		for(int i=1;i<=n;i++)if(t[i]!=2){vs=1,puts("-1");break;}
		if(vs)continue;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				cir.clear();
				findc(i,0);
				int num0=0,num1=0;
				for(auto it:cir)num0+=op[it]==1,num1+=op[it]==0;
				if(num0>num1)for(auto it:cir)op[it]^=1;
//				cout<<num0<<" sss "<<num1<<"\n";
				for(auto it:cir)if(op[it])ans.push_back(it);
			}
		}
		cout<<ans.size()<<"\n";
		for(auto it:ans)cout<<it<<" ";puts("");
	}
    return 0;
}