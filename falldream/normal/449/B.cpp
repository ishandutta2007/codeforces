#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define pa pair<long long,int>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
priority_queue<pa,vector<pa>,greater<pa> >q;
int n,m,K,head[MN+5],cnt=0,mn[MN+5],ans=0;long long d[MN+5],num[MN+5];
struct edge{int to,next,w;}e[MN*8+5];

inline void ins(int f,int t,int w)
{
	e[++cnt]=(edge){t,head[f],w};head[f]=cnt;	
	e[++cnt]=(edge){f,head[t],w};head[t]=cnt;
}

void Dij()
{
	memset(d,63,sizeof(d));q.push(make_pair(d[1]=0,1));num[1]=1;
	while(!q.empty())
	{
		while(!q.empty()&&d[q.top().second]!=q.top().first) q.pop();
		if(q.empty()) return;
		int x=q.top().second;q.pop();
		for(int i=head[x];i;i=e[i].next)
			if(d[x]+e[i].w<d[e[i].to]) q.push(make_pair(d[e[i].to]=d[x]+e[i].w,e[i].to)),num[e[i].to]=num[x];	
			else if(d[x]+e[i].w==d[e[i].to]) num[e[i].to]=min(num[e[i].to]+num[x],(long long)1e9);
	}
}

int main()
{
	n=read();m=read();K=read();
	memset(mn,63,sizeof(mn));
	for(int i=1,j,k;i<=m;++i) j=read(),k=read(),ins(j,k,read());
	for(int i=1;i<=K;++i)
	{
		int s=read(),len=read();
		if(mn[s]<=1e9) ++ans;
		mn[s]=min(mn[s],len);
	}	
	for(int i=2;i<=n;++i) if(mn[i]<=1e9) ins(1,i,mn[i]);
	Dij();
	//for(int i=1;i<=n;++i) cout<<d[i]<<" "<<num[i]<<" "<<mn[i]<<endl;
	for(int i=1;i<=n;++i) if(mn[i]<=1e9&&(mn[i]>d[i]||(mn[i]==d[i]&&num[i]>1))) ++ans;
	printf("%d\n",ans); 
	return 0;
}