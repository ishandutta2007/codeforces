#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

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

int n;
#define Maxn 505
int b[Maxn][Maxn];
int p[Maxn];int all;

inline void gao(int x,int y,int id){
	b[x][y]=id;
	--all;
	if(!all)return;
	if(y>1&&!b[x][y-1]){
		gao(x,y-1,id);
		if(!all)return;
	}
	if(x<n&&!b[x+1][y]){
		gao(x+1,y,id);
		if(!all)return;
	}
}

int main(){
	rd(n);
	rep(i,1,n){
		rd(p[i]);
	}
	rep(i,1,n){
		all=p[i];
		gao(i,i,p[i]);
	}
	rep(i,1,n){
		rep(j,1,i)printf("%d ",b[i][j]);
		puts("");
	}
	return 0;
}