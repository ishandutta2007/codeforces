#include<bits/stdc++.h>
using namespace std;
#define N 303
#define M 2000020
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
int n,m,Q,ans[M],a[N][N];
int f[N*N];
inline int getf(int x){
	return f[x]==x?x:f[x]=getf(f[x]);
}
inline int Merge(int x,int y){
	int fx=getf(x),fy=getf(y);
	if(fx==fy)return 0;
	f[fy]=fx;
	return 1;
}
inline int ID(int x,int y){
	return (x-1)*m+y;
}
const int d[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int mx,g[M];
vector<int> A[M],B[M],h[M];
int main(){
	n=read(),m=read(),Q=read();
	for(int i=1;i<=Q;++i){
		int x=read(),y=read(),c=read();
		mx=c;
		if(!g[c])g[c]=i;
		B[a[x][y]].push_back(ID(x,y));
		h[a[x][y]].push_back(i);
		A[c].push_back(ID(x,y));
		a[x][y]=c;
	}
	for(int i=1;i<=mx;++i){
		if(A[i].empty())continue;
		static int ok[N*N];
		for(auto x:A[i]){
			f[x]=x;
		}
		for(int j=0;j<(int)A[i].size();++j){
			int x=A[i][j];
			int px=(x-1)/m+1,py=(x-1)%m+1;
			ok[x]=1;
			for(int k=0;k<4;++k){
				int zx=px+d[k][0],zy=py+d[k][1];
				if(zx<1||zx>n||zy<1||zy>m)continue;
				int y=ID(zx,zy);
				if(!ok[y])continue;
				int z=Merge(x,y);
				ans[g[i]+j]-=z;
			}
		}
		for(auto x:A[i]){
			ok[x]=0;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			B[a[i][j]].push_back(ID(i,j));
			h[a[i][j]].push_back(Q+1);	
		}
	}
	for(int i=mx;i>=0;--i){
		if(B[i].empty())continue;
		static int ok[N*N];
		for(auto x:B[i]){
			f[x]=x;
		}
		for(int j=(int)B[i].size()-1;j>=0;--j){
			int x=B[i][j];
			int px=(x-1)/m+1,py=(x-1)%m+1;
			ok[x]=1;
			for(int k=0;k<4;++k){
				int zx=px+d[k][0],zy=py+d[k][1];
				if(zx<1||zx>n||zy<1||zy>m)continue;
				int y=ID(zx,zy);
				if(!ok[y])continue;
				int z=Merge(x,y);
				ans[h[i][j]]+=z;
			}
		}	
		for(auto x:B[i]){
			ok[x]=0;
		}
	}
	++ans[0];
	for(int i=1;i<=Q;++i){
		ans[i]+=ans[i-1];
		printf("%d\n",ans[i]);
	}
	return 0;
}