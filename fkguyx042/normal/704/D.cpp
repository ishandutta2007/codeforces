	#include<cstdio>
	#include<algorithm>
	#include<cstring>
	#include<iostream>
	#include<vector>
	#include<set>
	#include<map>
	#include<bitset>
	
	#define ls (t<<1)
	#define rs ((t<<1)+1)
	#define mid ((l+r)>>1)
	#define fi first
	#define se second
	#define mk make_pair
	#define pb push_back
	
	#define N 200005
	#define M 210005
	#define seed 23333
	#define Mo 998244353
	
	using namespace std;
	int i,j,m,n,p,k,in[M],out[M],ty,x[N],y[N],d,tot,sr[M],sc[M],st,ed,S,T,dis[M],Q[M],fox[M],G[M*10];
	int Min[N],Max[N];
	int ans[M];
	struct Node{int ed,before,flow;}s[M*10];
	map<int,int>row,col;
	map<int,int>::iterator it; 
	int bfs()
	{
	   Q[Q[0]=1]=st; memset(dis,-1,sizeof(dis));
	   dis[st]=0;
	   int l=1,i;
	   for (;l<=Q[0]&&dis[ed]==-1;++l)
	  {
	        int p=Q[l];
	        for (i=fox[p];i;i=s[i].before)
	          if (s[i].flow&&dis[s[i].ed]==-1)
	            {
	            	dis[s[i].ed]=dis[p]+1;
	            	Q[++Q[0]]=s[i].ed;
				}
	  }
	  return dis[ed]!=-1;
	}
	int dfs(int x,int flow)
	{
		if (x==ed) return flow;
		int i; int nowans=0,a;
		for (i=fox[x];i&&flow;i=s[i].before)
		  if (dis[s[i].ed]==dis[x]+1&&s[i].flow)
		  {
		  		   a=dfs(s[i].ed,min(flow,s[i].flow));
		  		   if (a) 
		  		   	{
		  		   		nowans+=a;
		  		   		flow-=a;
		  		   		s[i].flow-=a;
		  		   		s[i^1].flow+=a;
					}
		  }
		 if (!nowans) dis[x]=(int)1e9;
		 return nowans;
	}
	int maxflow()
	{ int j;
	  int ans=0;
	    while (bfs())
	    { j=dfs(st,(int)1e9);  while (j) {ans+=j;j=dfs(st,(int)1e9);} }
	  return ans;
	}
	int Rcost,Ccost,k1=1;
	void add(int x,int y,int up,int down)
	{
			if (up>down) {  puts("-1"); exit(0); }
			out[x]+=up; in[y]+=up;
			down-=up;
			if (!down) return;
			s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; s[k1].flow=down;
			s[++k1].ed=x; s[k1].before=fox[y]; fox[y]=k1; s[k1].flow=0;
	}
	int main()
	{
		scanf("%d%d",&n,&m);
		scanf("%d%d",&Rcost,&Ccost); 
		for (i=1;i<=n;++i) 
		{
			scanf("%d%d",&x[i],&y[i]);
			if (!row[x[i]]) row[x[i]]=++tot;
			if (!col[y[i]]) col[y[i]]=++tot;
			sr[row[x[i]]]++;
			sc[col[y[i]]]++;
		}
		st=++tot; ed=++tot; S=++tot; T=++tot;
		for (i=1;i<=tot;++i) Min[i]=0,Max[i]=n; 
		for (i=1;i<=m;++i)
		{
				int x; 
				scanf("%d%d%d",&ty,&x,&d);
				if (ty==1)
				{
						if (!row[x]) continue;
						int ID=row[x];
						int res=(sr[ID]+d)/2;
						Min[ID]=max(Min[ID],sr[ID]-res);
						Max[ID]=min(Max[ID],res);
				}
				else 
				{
						if (!col[x]) continue;
						int ID=col[x];
						int res=(sc[ID]+d)/2;
						Min[ID]=max(Min[ID],sc[ID]-res);
						Max[ID]=min(Max[ID],res);
			    }	
		}
		for (it=row.begin();it!=row.end();++it)
		  if (it->se) add(S,it->se,Min[it->se],Max[it->se]);
		for (it=col.begin();it!=col.end();++it)
		  if (it->se) add(it->se,T,Min[it->se],Max[it->se]);
		for (i=1;i<=n;++i) add(row[x[i]],col[y[i]],0,1),G[k1-1]=i;
		for (i=1;i<=tot;++i) if (in[i]>out[i]) add(st,i,0,in[i]-out[i]);
		else if (in[i]<out[i]) add(i,ed,0,out[i]-in[i]);
		add(T,S,0,(int)1e9);
		maxflow();
		for (i=fox[st];i;i=s[i].before)
			if (s[i].flow)
			{
					puts("-1");
					return 0;
			}
		st=S; ed=T;
		int ss=maxflow(),cnt=0;
		printf("%I64d\n",1ll*ss*min(Rcost,Ccost)+1ll*(n-ss)*max(Rcost,Ccost));
		for (it=row.begin();it!=row.end();++it)
		{
					int now=it->se;
						for (i=fox[now];i;i=s[i].before)
						if (s[i].flow==0) ans[G[i]]=1,++cnt;
		}
		char c,s;
		if (Rcost>Ccost) c='b',s='r'; else c='r',s='b'; 
		for (i=1;i<=n;++i)
		  if (ans[i]) printf("%c",c); else printf("%c",s);
	}