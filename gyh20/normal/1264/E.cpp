#pragma GCC optimize(200000)
#include<iostream>
#include<cstdio>
#include<deque>
#include<cstring>
#define re register
using namespace std;
struct edge{
	int next,w,to,ww,fr;
}e[3500005];
const int Mxdt=100000;
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read()
{
	int res=0;char ch=gc();
	while(ch<'0'||ch>'9')ch=gc();
	while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=gc();
	return res;
}
int head[10302],b,c,d,n,m,cnt=1,S,T,dis[10302],pre[10302],p[10302],ans1,ans2,vv[10302],a[102][102],sum,f[102][102],in[102];
inline void add(register int u,register int v,register int w,re int ww){
      e[++cnt].to=v;
      e[cnt].ww=ww;
      e[cnt].w=w;
      e[cnt].fr=u;
      e[cnt].next=head[u];
      head[u]=cnt;
      e[++cnt].to=u;
      e[cnt].fr=v;
      e[cnt].ww=-ww;
      e[cnt].next=head[v];
      head[v]=cnt;
}   
deque <int> q;
inline int spfa(register int s,register int t){

	memset(p,0,sizeof(p));
    memset(dis,127,sizeof(dis));
    memset(vv,0,sizeof(vv));
    bool zzw=0;
	q.push_front(s);
	dis[s]=0;
	vv[s]=1;
	while(!q.empty()){
		int r=q.front();
		q.pop_front();
		vv[r]=0;
		if(r==t)zzw=1;
        for(register int i=head[r];i;i=e[i].next){
			if(e[i].w&&dis[e[i].to]>dis[r]+e[i].ww){
				dis[e[i].to]=dis[r]+e[i].ww;
				p[e[i].to]=i;
				if(!vv[e[i].to]){
			
				vv[e[i].to]=1;
				if(!q.empty()&&dis[e[i].to]<dis[q.front()])
			    q.push_front(e[i].to);
			    else q.push_back(e[i].to);	
				}
			}
		}
	}
	if(zzw)return 1;
	return 0;
}
#define min mn
inline int min(re int x,re int y){
	return x<y?x:y;
}
inline void dfs(){
	int tmp=0x7fffffff,cnt=0,pp;
	for(re int i=T;i!=S;i=e[pp^1].to){
		pp=p[i];
		cnt+=e[pp].ww;
	tmp=min(tmp,e[pp].w);
}
	for(re int i=T;i!=S;i=e[pp^1].to){
		pp=p[i];
		e[pp].w-=tmp,e[pp^1].w+=tmp;
	}

	ans1+=tmp,ans2+=tmp*cnt;
}

signed main(){
//	freopen("a.out","w",stdout);
    n=read();
	S=0;
	T=n*n+n+1;
	int num=n;
	re int mm=read();
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=n;++j)a[i][j]=2;
	for(re int i=1;i<=n;++i)a[i][i]=0;
	while(mm--){
		re int x=read(),y=read();
		a[x][y]=1,a[y][x]=0;
	}
	
	for(re int i=1;i<=n;++i){
		for(re int j=1;j<=n;++j){
			if(i==j)continue;
			if(!a[i][j])continue;
		
		//	add(S,num,1,0);
		
			if(a[i][j]==1)++in[i];
			else if(a[i][j]==2&&i<j){	++num;
				add(num,i,1,0);
				add(num,j,1,0);
				add(S,num,1,0);
			}
		}
	}
	for(re int i=1;i<=n;++i){ans2+=(in[i]*(in[i]-1))/2;
		for(re int j=in[i];j<n;++j)add(i,T,1,j);
	}
	while(spfa(S,T))dfs();
	int tmp=n;
	for(re int i=1;i<=n;++i){
		for(re int j=1;j<=n;++j){
			if(a[i][j]!=2)printf("%d",a[i][j]);
			else{
				if(i<j){
				++tmp;
				if(e[head[tmp]].to==S)head[tmp]=e[head[tmp]].next;
				if(e[head[tmp]].w)f[i][j]=1;
				else f[i][j]=0;		}
				else f[i][j]=1-f[j][i];
				printf("%d",f[i][j]);
			}
		}
		putchar('\n');
	}
}