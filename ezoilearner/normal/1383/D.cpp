#include<bits/stdc++.h>
using namespace std;
typedef pair<bool,bool> pbb;
typedef pair<int,int> pii;
int n,m,x,y;
#define Maxn 70010
#define cout cerr
#define FR first
#define SE second
int A[255][255];
int ans[255][255];
pbb seq[Maxn];pii Q[Maxn];int hd,tl;

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	rd(n);rd(m);
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)rd(A[i][j]);
	for(int i=1;i<=n;++i){
		int mx=1;
		for(int j=2;j<=m;++j)
			if(A[i][j]>A[i][mx])mx=j;
		seq[A[i][mx]].FR=true;
	}
	for(int j=1;j<=m;++j){
		int mx=1;
		for(int i=2;i<=n;++i)
			if(A[i][j]>A[mx][j])mx=i;
		seq[A[mx][j]].SE=true;
	}
	for(int i=n*m;i>=1;--i){
		if(seq[i].FR&&seq[i].SE){
			x++;y++;
			ans[x][y]=i;
			for(int j=y-1;j>=1;--j)Q[tl++]=pii(x,j);
			for(int j=x-1;j>=1;--j)Q[tl++]=pii(j,y);
		}
		if(seq[i].FR&&!seq[i].SE){
			x++;ans[x][y]=i;
			for(int j=y-1;j>=1;--j)Q[tl++]=pii(x,j);
		}
		if(!seq[i].FR&&seq[i].SE){
			y++;ans[x][y]=i;
			for(int j=x-1;j>=1;--j)Q[tl++]=pii(j,y);
		}
		if(!seq[i].FR&&!seq[i].SE){
			ans[Q[hd].FR][Q[hd].SE]=i;hd++;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
}