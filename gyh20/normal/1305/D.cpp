#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0'){
		t=(t<<3)+(t<<1)+v-48;
		v=getchar();
	}
	return t;
}
struct edge{
	int to,next;
}e[2002];
int n,head[1002],cnt,del[1002],zx,siz[1002],mns;
inline void add(re int x,re int y){
	e[++cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
inline void get(re int x,re int y){
	siz[x]=1;
	int mxs=0;
	for(re int i=head[x];i;i=e[i].next){
		if(e[i].to!=y&&!del[e[i].to]){
			get(e[i].to,x);
			siz[x]+=siz[e[i].to];
			mxs=max(mxs,siz[e[i].to]);
		}
	}
	mxs=max(mxs,n-siz[x]);
	if(mxs<mns){
		mns=mxs;
		zx=x;
	}
}
inline void dfs(re int x,re int y){
	siz[x]=1;
	for(re int i=head[x];i;i=e[i].next){
		if(e[i].to!=y&&!del[e[i].to]){
			dfs(e[i].to,x);
			siz[x]+=siz[e[i].to];
		}
	}
}
inline void find(re int x){
	mns=1e9;
	get(x,x);
	x=zx;
	dfs(x,x);
	if(siz[x]==1){
		printf("! %d\n",x);
		fflush(stdout);
		return;
	}
	else if(siz[x]==2){
		int y;
		for(re int i=head[x];i;i=e[i].next){
			
			if(!del[e[i].to]){
				y=e[i].to;
				break;
			}
		}
		printf("? %d %d\n",x,y);
		fflush(stdout);
		x=read();
		printf("! %d\n",x);
		fflush(stdout);
		return;
	}
	else{
		int lst=0,lst1=0;
		for(re int i=head[x];i;i=e[i].next){
			if(!del[e[i].to]){
				if(!lst)lst=e[i].to;
				else lst1=e[i].to;
			}
		}putchar('\n');
		printf("? %d %d\n",lst,lst1);
		fflush(stdout);
		int tmp=read();
		if(tmp==lst){
			del[x]=1;
			n=siz[lst];
			find(lst);
		}
		else if(tmp==lst1){
			del[x]=1;
			n=siz[lst1];
			find(lst1);
		}
		else{
			del[lst]=del[lst1]=1;
			n-=siz[lst];
			n-=siz[lst1];
			find(x);
		}
	}
}
int x,y;
int main(){
	n=read();
	for(re int i=1;i<n;++i){
		x=read();
		y=read();
		add(x,y);
		add(y,x);
	}
	find(1);
}