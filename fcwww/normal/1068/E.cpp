#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;
#define N 100050
#define GG puts("No"); exit(0)
int n,head[N],to[N<<1],nxt[N<<1],cnt,mxd[N];
int root,K;
inline void add(int u,int v) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt;
}
void df1(int x,int y) {
	int i;
	for(i=head[x];i;i=nxt[i]) if(to[i]!=y) {
		df1(to[i],x);
		mxd[x]=max(mxd[x],mxd[to[i]]+1);
	}
	if(mxd[x]==K) {
		root=x; return ;
	}
}
void df2(int x,int y,int d) {
	int i;
	int flg=0;
	for(i=head[x];i;i=nxt[i]) if(to[i]!=y) {
		df2(to[i],x,d+1); flg=1;
	}
	if(!flg&&d!=K) {
		GG;
	}
}
void df3(int x,int y) {
	int i;
	int ss=0;
	for(i=head[x];i;i=nxt[i]) if(to[i]!=y) {
		df3(to[i],x); ss++;
	}
	if(ss<3&&ss) {
		GG;
	}
}
int main() {
	scanf("%d%d",&n,&K);
	int i,x,y;
	for(i=1;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	df1(1,0);
	if(!root) {
		GG;
	}
	df2(root,0,0);
	df3(root,0);
	puts("Yes");
}