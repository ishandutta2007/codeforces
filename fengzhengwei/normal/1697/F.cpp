#include<bits/stdc++.h>
#define ll long long 
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchargc
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
void wt(int x)
{
	if(x>9)wt(x/10);
	pc(x%10+'0',0);
}
void wts(int x,char c)
{
	if(x<0)x=-x,pc('-',0);
	wt(x),pc(c,0);
}
const int xx=2e4+5;
namespace two_sat
{
	const int xx=2e6+5;
	struct nod{int next,to;}e[xx<<1];
	int cnt,h[xx],tt;
	void add(int x,int y){/*cerr<<x<<" "<<y<<"#$\n",*/cnt++,e[cnt]={h[x],y},h[x]=cnt;}
	int dfn[xx],low[xx],stk[xx],vis[xx],bel[xx],to[xx],top,cst,bcc;
	void cl(){memset(h,0,sizeof(h[0])*(tt+1));tt=0;cnt=0;}
	void tj(int x)
	{
		dfn[x]=low[x]=++cst,stk[++top]=x,vis[x]=1;
		for(int i=h[x];i;i=e[i].next)
		{
			if(!dfn[e[i].to])tj(e[i].to),low[x]=min(low[x],low[e[i].to]);
			else if(vis[e[i].to])low[x]=min(low[x],dfn[e[i].to]);
		}
		if(dfn[x]==low[x])
		{
			++cst,++bcc;
			while(stk[top]!=x)bel[stk[top]]=bcc,vis[stk[top--]]=0;
			bel[stk[top]]=bcc,vis[stk[top--]]=0;
		}
	}
	//01 
	vector<int> run(vector<pair<int,int> >&v)
	{
		for(int i=1;i<=tt;i++)
			dfn[i]=low[i]=stk[i]=vis[i]=bel[i]=0;
		top=cst=bcc=0;
		for(int i=1;i<=tt;i++)if(!dfn[i])tj(i);
//		for(int i=1;i<=tt;i++)cerr<<dfn[i]<<"\n";
		for(auto it:v)if(bel[it.first]==bel[it.second])return /*cerr<<it.first<<" "<<it.second<<"\n",*/(vector<int>){};
		vector<int>ans;
		ans.resize(v.size());
		for(auto it:v)to[bel[it.first]]=bel[it.second];
		for(auto it:v)to[bel[it.second]]=bel[it.first];
		for(int i=1;i<=bcc;i++)vis[i]=0;
		for(int i=1;i<=bcc;i++)if(!vis[i])vis[to[i]]=1;
		for(int i=0;i<(int)v.size();i++)
		{
			if(!vis[bel[v[i].first]])ans[i]=0;
			else ans[i]=1;
		}
		return ans;
	}
}
int T,id[xx][11][2],n,m,k;
int main(){
	T=read();
	while(T--)
	{
		n=read(),m=read(),k=read();
		two_sat::cl();
		int &tt=two_sat::tt;
		//0>= 
		//01 
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k;j++)
				id[i][j][0]=++tt,id[i][j][1]=++tt;
			for(int j=1;j<k;j++)two_sat::add(id[i][j][1],id[i][j+1][1]),two_sat::add(id[i][j+1][0],id[i][j][0]);
		}
		for(int i=1;i<n;i++)
			for(int j=1;j<=k;j++)two_sat::add(id[i][j][0],id[i+1][j][0]),two_sat::add(id[i+1][j][1],id[i][j][1]);
		for(int i=1;i<=n;i++)two_sat::add(id[i][1][1],id[i][1][0]);
		for(int i=1;i<=m;i++)
		{
			int op=read();
			if(op==1)
			{
				int I=read(),x=read();
				// 
				if(x<k)two_sat::add(id[I][x][0],id[I][x+1][0]),two_sat::add(id[I][x+1][1],id[I][x][1]);
				if(x==k)two_sat::add(id[I][x][0],id[I][x][1]);
			}
			if(op==2)
			{
				int I=read(),J=read(),x=read();
				// 
				for(int j=1;j<=k;j++)
				{
					int w=x-j+1;
					if(w<1)two_sat::add(id[I][j][0],id[I][j][1]);
//					if(w>=1&&w<=k)
//				cerr<<j<<" "<<w<<"!\n";
					if(w>=1&&w<=k)
						two_sat::add(id[I][j][0],id[J][w][1]),two_sat::add(id[J][w][0],id[I][j][1]);
				}
//					for(int w=1;w<=k;w++)
//						if(j+w>x)
//						{
//							two_sat::add(id[I][j][0],id[J][w][1]),two_sat::(id[J][w][0],id[I][j][1]);
//							break;
//						}
			}
			if(op==3)
			{
				int I=read(),J=read(),x=read();
				// 
				for(int j=1;j<=k;j++)//<j 
				{
					int w=x-j+1;
					if(w>k)two_sat::add(id[I][j][1],id[I][j][0]);
//					if(w>=1&&w<=k)
//					cerr<<j+1<<" "<<w<<"#!\n";
					if(w>=1&&w<=k)
						two_sat::add(id[I][j][1],id[J][w][0]),two_sat::add(id[J][w][1],id[I][j][0]);
				}
//					for(int w=1;w<=k;w++)
//						if(j+w>x)
//							two_sat::add(id[I][j][0],id[J][w][1]),two_sat::(id[J][w][0],id[I][j][1]);
			}
		}
		vector<pair<int,int> >v;
		vector<int>ans;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k;j++)v.push_back(make_pair(id[i][j][0],id[i][j][1]));
		ans=two_sat::run(v);
		if(!ans.size()){puts("-1");continue;}
		int re=0;
		for(int i=1;i<=n;i++)
		{
			int mx=0;
			for(int j=1;j<=k;j++)if(ans[re++]==0)mx=max(mx,j);
			cout<<mx<<" ";
		}
		puts("");
	}
	pc('1',1);
	return 0;
}