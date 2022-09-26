#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int mod=998244353;
#define N 1234
#define M 70
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
int n,a[N],m,tot,f[4][4],dp[N][4],g[N][4];
vector<pair<int,int> > col[N];
struct Matrix{
	int g[M][M];
	Matrix(){memset(g,0,sizeof(g));}
	Matrix operator *(const Matrix a){
		Matrix b;
		for(int i=0;i<=tot;++i){
			for(int j=0;j<=tot;++j){
				for(int k=0;k<=tot;++k){
					b.g[i][j]=(b.g[i][j]+1LL*g[i][k]*a.g[k][j])%mod;
				}
			}
		}
		return b;
	}
	Matrix operator |(const Matrix a){
		Matrix b;
		for(int j=0;j<=tot;++j){
			for(int k=0;k<=tot;++k){
				b.g[1][j]=(b.g[1][j]+1LL*g[1][k]*a.g[k][j])%mod;
			}
		}
		return b;
	}
}A[33];
inline int get_mex(vector<int> &myh){
	for(int i=0;;++i){
		bool ok=false;
		for(auto x:myh){
			if(x==i){
				ok=true;break;
			}
		}
		if(!ok)return i;
	}
}
int normal(int x,int y,int z){
	return x|(y<<2)|(z<<4);
}
void mpow(Matrix &a,int b){
	for(int i=30;i>=0;--i){
		if(b>>i&1){
			a=a|A[i];
		}
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	m=read();
	for(int i=1;i<=m;++i){
		int x=read(),y=a[x]-read()+1,z=read();
		col[x].emplace_back(y,z);
	}
	for(int i=1;i<=n;++i){
		sort(col[i].begin(),col[i].end(),greater<pair<int,int> >());
	} 
	for(int i=1;i<=3;++i){
		for(int j=1;j<=3;++j){
			f[i][j]=read();
		}
	}
	for(int x=0;x<=3;++x){
		for(int y=0;y<=3;++y){
			for(int z=0;z<=3;++z){
				int s=normal(x,y,z);
				for(int p=1;p<=3;++p){
					static vector<int> zyk;
					zyk.clear();
					if(f[p][1])zyk.push_back(x);
					if(f[p][2])zyk.push_back(y);
					if(f[p][3])zyk.push_back(z);
					int w=get_mex(zyk);
					int t=normal(w,x,y);
					++A[0].g[s][t];
				}
			}
		}
	}
	tot=(1<<6)-1;
	for(int i=1;i<=30;++i){
		A[i]=A[i-1]*A[i-1];
	}
	for(int u=1;u<=n;++u){
		Matrix T;
		T.g[1][tot]=1;
		int las=a[u]+1;
		for(auto [pos,p]:col[u]){
			mpow(T,las-pos-1);
			las=pos;
			Matrix gu;
			for(int x=0;x<=3;++x){
				for(int y=0;y<=3;++y){
					for(int z=0;z<=3;++z){
						int s=normal(x,y,z);
						static vector<int> zyk;
						zyk.clear();
						if(f[p][1])zyk.push_back(x);
						if(f[p][2])zyk.push_back(y);
						if(f[p][3])zyk.push_back(z);
						int w=get_mex(zyk);
						int t=normal(w,x,y);
						++gu.g[s][t];
					}
				}
			}
			T=T*gu;
		}
		mpow(T,las-1);
		for(int i=0;i<=tot;++i){
			g[u][i&3]=(g[u][i&3]+T.g[1][i])%mod;
		}
	}
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int x=0;x<=3;++x){
			for(int y=0;y<=3;++y){
				dp[i][x^y]=(dp[i][x^y]+1LL*dp[i-1][x]*g[i][y])%mod;
			}
		}
	}
	printf("%d\n",dp[n][0]);
	return 0;
}