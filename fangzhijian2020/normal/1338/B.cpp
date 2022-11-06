#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,x,y,rd[100005],root,ans,h[100005],cnt;
struct edge{int to,next;}e[200005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;++rd[x];
}
int anss=1;
bool dfs1(int x,int prt){
	int i,y,tmp=1,tp=-1;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt)continue;
		if(tp==-1)tp=dfs1(y,x);
		else{
			if(tp!=dfs1(y,x)){
				anss=0;return 0;
			}
		}
	}
	return tmp^tp;
}
bool DFS(int x,int prt){
	int i,y,tmp=0;if(rd[x]==1)return 1;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt)continue;
		tmp+=DFS(y,x);
	}
	ans-=max(0,tmp-1);return 0;
}
int main(){
	n=read();ans=n-1;
	for(int i=1;i<n;++i){
		x=read();y=read();
		add(x,y);add(y,x);
	}
	for(int i=1;i<=n;++i){
		if(rd[i]>1)root=i;
	}
	dfs1(root,0);if(anss)putchar('1');else putchar('3');
	DFS(root,0);printf(" %d\n",ans);
	return 0;
}