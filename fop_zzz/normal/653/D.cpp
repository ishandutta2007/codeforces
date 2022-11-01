#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <ctime>
#include <map>
#include <queue>
#include <cstdlib>
#include <string>
#include <climits>
#include <set>
#include <vector>
#include <complex>
#include <iomanip>
using namespace std;
typedef long double D;
inline int read(){
	int k=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){k=k*10+ch-'0';ch=getchar();}
	return k*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);putchar(x%10+'0');
}
inline void writeln(int x){
	write(x);puts("");
}
const int N=1010;
int nedge=0,p[2*N],nex[2*N],head[2*N],c[2*N];
inline void addedge(int a,int b,int v){
	p[++nedge]=b;nex[nedge]=head[a];head[a]=nedge;
	c[nedge]=v;
}
inline int fan(int x){return (x&1)?x+1:x-1;}
int n,m,X,s,t;
int dist[N],cur[N];
inline bool bfs(int s,int t){
	queue<int>q;q.push(s);
	memset(dist,-1,sizeof dist);dist[s]=1;
	while(!q.empty()){
		int now=q.front();q.pop();
		for(int k=head[now];k;k=nex[k])if(c[k]&&dist[p[k]]==-1){
			dist[p[k]]=dist[now]+1;q.push(p[k]);
		}
	}
	return dist[t]>-1;
}
inline int dfs(int x,int low){
	if(x==t)return low;
	int a,used=0;
	for(int k=cur[x];k;k=nex[k])if(c[k]&&dist[p[k]]==dist[x]+1){
		a=dfs(p[k],min(c[k],low-used));
		if(a)c[k]-=a,c[fan(k)]+=a,used+=a;
		if(c[k])cur[x]=k;
		if(used==low)break;
	}
	if(!used)dist[x]=-1;
	return used;
}
inline int dinic(){
	int flow=0;
	while(bfs(s,t)){
		for(int i=s;i<=t;i++)cur[i]=head[i];
		flow+=dfs(s,1e9);
	}
	return flow;
}
struct ppap{int x,y,v;}a[N];
inline bool check(D x){
	nedge=0;memset(head,0,sizeof head);
	s=1;t=n;
	for(int i=1;i<=m;i++){
		long long p=(long long)(D)a[i].v/x;
		if(p>X)p=X;
		addedge(a[i].x,a[i].y,p);
		addedge(a[i].y,a[i].x,0);
	}
	int ss=dinic();
	return ss>=X;
}
int main()
{
	n=read();m=read();X=read();
	for(int i=1;i<=m;i++){
		a[i].x=read();a[i].y=read();a[i].v=read();
	}
	D l=0,r=1e9;
	for(int i=1;i<=100;i++){
		D mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	l*=X;
	cout<<setiosflags(ios::fixed);
	cout<<setprecision(8)<<l<<endl;
	return 0;
}