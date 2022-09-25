#include<bits/stdc++.h>
using namespace std;
#define N 72
typedef long long ll;
int X,K,n,Q,c[9],m,id[1<<8];
struct Matrix{
	ll g[N][N];
	Matrix(){memset(g,0x3f,sizeof(g));}
	friend Matrix operator * (const Matrix &a,const Matrix &b){
		Matrix c;
		for(int i=1;i<=m;++i){
			for(int j=1;j<=m;++j){
				for(int k=1;k<=m;++k){
					c.g[i][j]=min(c.g[i][j],a.g[i][k]+b.g[k][j]);
				}
			}
		}
		return c;
	}	
}A,e;
Matrix mpow(Matrix a,int b){
	Matrix ans=e;
	while(b){
		if(b&1)ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;	
}
pair<int,int> stone[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>X>>K>>n>>Q;
	for(int i=1;i<=K;++i){
		cin>>c[i];
	}
	for(int i=0;i<(1<<K);++i){
		if(__builtin_popcount(i)==X){
			id[i]=++m;
		}
	}
	for(int i=1;i<=m;++i){
		e.g[i][i]=0;
	}
	for(int s=0;s<(1<<K);++s){
		if(id[s]){
			if(!(s&1)){
				A.g[id[s]][id[s>>1]]=0;
			}
			else{
				for(int i=1;i<=K;++i){
					if(!(s>>i&1)){
						A.g[id[s]][id[(1<<i|s)>>1]]=c[i];	
					}
				}
			}
		}	
	}
	Matrix ans;
	ans.g[1][1]=0;
	int now=1;
	ll qwq=0;
	for(int i=1;i<=Q;++i){
		cin>>stone[i].first>>stone[i].second;
	}
	sort(stone+1,stone+Q+1);
	for(int i=1;i<=Q;++i){
		auto [x,w]=stone[i];
		if(x>n-X){
			qwq+=w;continue;
		}
		ans=ans*mpow(A,x-now);
		for(int s=0;s<(1<<K);++s){
			if(id[s]&&s&1)ans.g[1][id[s]]+=w;
		}
		now=x;
	}
	ans=ans*mpow(A,n-X+1-now);
	cout<<ans.g[1][1]+qwq<<'\n';
	return 0;
}