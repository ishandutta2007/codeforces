#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define lowbit(x) x&-x
#define MAXN 200001
#define B 500
int N,M,p[MAXN],K,l[MAXN],r[MAXN],opt[MAXN],x[MAXN],y[MAXN],in[MAXN],tot,id[MAXN];ll a[MAXN],val[MAXN],sum[MAXN];vector<int>pos[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get();For(i,1,N)a[i]=get();For(i,1,N)p[i]=get();M=get();For(i,1,M)opt[i]=get(),x[i]=get(),y[i]=get();while(r[K]<M)K++,l[K]=r[K-1]+1,r[K]=min(B*K,M);
	For(i,1,K)
	{
		For(j,1,N)sum[j]=sum[j-1]+a[j];For(j,1,N)in[j]=val[j]=0,pos[j].clear();tot=0;
		For(j,l[i],r[i])if(opt[j]==2)in[x[j]]=x[j];else if(opt[j]==3)in[x[j]]=x[j],in[y[j]]=y[j];
		For(j,1,N)
		{
			if(in[j]==j)id[++tot]=j;if(in[j])continue;int x=p[j];while(x!=j&&!in[x])x=p[x];
			int c=x==j?-1:in[x];x=j;do in[x]=c,x=p[x];while(x!=j&&!in[x]);
		}
		For(j,1,N)if(in[j]>0)pos[in[j]].push_back(j);
		For(j,l[i],r[i])
		{
			if(opt[j]==1){ll ans=sum[y[j]]-sum[x[j]-1];For(k,1,tot)ans+=val[id[k]]*(upper_bound(pos[id[k]].begin(),pos[id[k]].end(),y[j])-lower_bound(pos[id[k]].begin(),pos[id[k]].end(),x[j]));cout<<ans<<'\n';}
			else if(opt[j]==2){int u=in[x[j]];do val[u]+=y[j],u=in[p[u]];while(u!=in[x[j]]);}else swap(p[x[j]],p[y[j]]);
		}
		For(j,1,N)if(in[j]>0)a[j]+=val[in[j]];
	}
	return 0;
}