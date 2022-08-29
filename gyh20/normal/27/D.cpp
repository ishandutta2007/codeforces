#include<iostream>
#include<cstdio>
#include<stack>
#define re register
using namespace std;
struct edge{
	int to,next;
}e[100002];
stack <int> s;
int m,n,head[100002],p,cnt,dfn[100002],low[100002],tie,k,bl[100002],opp[100002],ans[100002];
bool st[100002],vs[100002];
inline int read(){
	int t=0;
	char v=getchar();
	while(v<'0'||v>'9'){v=getchar();
	}
	while(v>='0'&&v<='9'){
		t=(t<<3)+(t<<1)+v-'0';
		v=getchar();
	}
	return t;
}
inline int f(re int x){
	return x+m;
}
inline int bu(re int x,re int y){
	e[++cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
inline int tarjan(re int p){
	s.push(p);
	st[p]=1;
	dfn[p]=++tie;
	low[p]=dfn[p];
	for(re int i=head[p];i;i=e[i].next){
		if(!dfn[e[i].to]){
			tarjan(e[i].to);
			low[p]=min(low[p],low[e[i].to]);
		}
		else if(st[e[i].to])low[p]=min(low[p],dfn[e[i].to]);
	}//cout<<p<<" "<<low[p]<<" "<<dfn[p]<<endl;
	if(low[p]==dfn[p]){
		int tmp;
		++k;
		do{ tmp=s.top();
			bl[tmp]=k;
			st[tmp]=0;
			
			s.pop();
		}while(tmp!=p);
	}
}
inline void dfs(re int x){
	if(ans[x])return;
	ans[x]=1;
	for(re int i=head[x];i;i=e[i].next)dfs(e[i].to);
}
int a[1002],b[1002];
int main(){
n=read();
m=read();
for(re int i=1;i<=m;++i){
	a[i]=read();
	b[i]=read();
	if(a[i]>b[i])swap(a[i],b[i]);
}
for(re int i=1;i<m;++i){
	for(re int j=i+1;j<=m;++j){
		if((a[i]<a[j]&&b[i]<b[j]&&b[i]>a[j])||(a[i]>a[j]&&b[i]>b[j]&&a[i]<b[j])){
			bu(i,j+m);
			bu(j+m,i);
			bu(i+m,j);
			bu(j,i+m);
		}
	}
}
for(re int i=1;i<=m<<1;++i)if(!dfn[i])tarjan(i);
//cout<<bl[1]<<" "<<bl[2]<<" "<<bl[3]<<" "<<bl[4]<<" "<<bl[5]<<" "<<bl[6];
for(re int i=1;i<=(m<<1);++i)
    if(bl[i]==bl[i+m]){
	puts("Impossible");
	return 0;
}
for(re int i=1;i<=m;++i){
	if(ans[i]||ans[i+m])continue;
	dfs(i);
}
for(re int i=1;i<=m;++i)putchar(ans[i]?'i':'o');
	return 0;
}