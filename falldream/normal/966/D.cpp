#include<bits/stdc++.h>
#define MN 300000
#define P(x,y) make_pair(min(x,y),max(x,y))
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
map<pair<int,int>,bool>mp;
int n,m,head[MN+5],cnt,d[MN+5],q[MN+5],top,ans,Ans[MN+5],from[MN+5],now,vis[MN+5],gg[MN+5];
struct edge{int to,next;}e[MN*2+5];
inline void ins(int f,int t)
{
	mp[P(f,t)]=1;
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;
	e[++cnt]=(edge){f,head[t]};head[t]=cnt;	
}
void Bfs(int s,int ban)
{
	for(int i=1;i<=top;++i) d[q[i]]=1e9,from[q[i]]=0;
	d[q[top=1]=s]=0;
	for(int i=1;i<=top;++i)	
		for(int j=head[q[i]];j;j=e[j].next)
			if(e[j].to!=ban&&d[q[i]]+1<d[e[j].to])
				d[q[++top]=e[j].to]=d[q[i]]+1,from[e[j].to]=q[i];
}
int main()
{
    n=read();m=read();
    memset(d,63,sizeof(d));
    for(int i=1;i<=m;++i) ins(read(),read());
    Bfs(1,0);
    if(d[n]<1e8)
	{
		for(int j=n;j;j=from[j]) Ans[++ans]=j;
		for(int l=1,r=ans;l<r;++l,--r) swap(Ans[l],Ans[r]);
	}
	else ans=1e9;
    for(int i=1;i<n;++i) if(d[i]==2&&ans>5) 
    {
    	ans=5;
    	Ans[1]=1;Ans[2]=from[i];Ans[3]=i;
    	Ans[4]=1;Ans[5]=n;
    }
    for(int i=head[1];i;i=e[i].next) if(ans>6)
    {
    	int x=e[i].to;if(gg[x]) continue;Bfs(x,1);
    	for(int j=1;j<=top&&ans>6;++j) if(d[q[j]]==2)
    	{
    		ans=6;
    		Ans[1]=1;Ans[2]=x;Ans[3]=from[q[j]];Ans[4]=q[j];
    		Ans[5]=x;Ans[6]=n;
    	}
    	for(int j=2;j<top&&ans>6;++j) for(int k=j+1;k<=top&&ans>6;++k)
    		if(!mp[P(q[j],q[k])])
    		{
				ans=6;
				Ans[1]=1;Ans[2]=q[j];Ans[3]=x;
				Ans[4]=q[k];Ans[5]=q[j];Ans[6]=n;
    		}
    	for(int j=2;j<=top;++j) gg[q[j]]=1;
    }
    if(ans>1e8) puts("-1");
	else 
	{
		printf("%d\n",ans-1);
		for(int i=1;i<=ans;++i) printf("%d ",Ans[i]);	
	}
    return 0;
}