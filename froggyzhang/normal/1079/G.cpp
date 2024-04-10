#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 300030
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,l[N][20],r[N][20],lg[N],a[N];
int f[N][20],g[N][20];
#define Max(x,y) (r[x][0]>r[y][0]?x:y)
#define Min(x,y) (l[x][0]<l[y][0]?x:y)
inline int Query1(int L,int R){
	int k=lg[R-L+1];
	return Min(f[L][k],f[R-(1<<k)+1][k]);
}
inline int Query2(int L,int R){
	int k=lg[R-L+1];
	return Max(g[L][k],g[R-(1<<k)+1][k]);
}
int main(){
	n=read();
	if(n==1)return !printf("0");
	for(int i=1;i<=n;++i){
		a[i]=a[n+i]=a[n+n+i]=read();
	}
	for(int i=1;i<=3*n;++i){
		l[i][0]=max(1,i-a[i]);
		r[i][0]=min(3*n,i+a[i]);
		f[i][0]=g[i][0]=i;
	}
	for(int i=2;i<=n;++i){
		lg[i]=lg[i>>1]+1;
	}
	for(int j=1;j<=19;++j){
		for(int i=1;i+(1<<j)-1<=3*n;++i){
			f[i][j]=Min(f[i][j-1],f[i+(1<<j-1)][j-1]);
			g[i][j]=Max(g[i][j-1],g[i+(1<<j-1)][j-1]);
		}
	}
	for(int j=1;j<=19;++j){
		for(int i=1;i<=3*n;++i){
			int x=Query1(l[i][j-1],r[i][j-1]);
			int y=Query2(l[i][j-1],r[i][j-1]);
			l[i][j]=min(l[x][j-1],l[y][j-1]);
			r[i][j]=max(r[x][j-1],r[y][j-1]);
		}
	}
	for(int i=n+1;i<=(n<<1);++i){
		int L=i,R=i,ans=0;
		for(int j=19;j>=0;--j){
			if(max(r[L][j],r[R][j])-min(l[L][j],l[R][j])+1>=n)continue;
			int nl=Query1(l[L][j],r[R][j]);
			int nr=Query2(l[L][j],r[R][j]);
			L=nl,R=nr;
			ans|=1<<j;
		}
		++ans;
		printf("%d ",ans);
	}
	return 0;
}