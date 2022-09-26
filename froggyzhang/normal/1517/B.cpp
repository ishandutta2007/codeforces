#include<bits/stdc++.h>
using namespace std;
#define N 233
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
int T;
int n,m,b[N][N],ok[N][N];
vector<pair<int,int> > v;
void Solve(){
	n=read(),m=read();
	v.clear();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			b[i][j]=read();
			ok[i][j]=0;
			v.emplace_back(i,j);
		}
	}
	sort(v.begin(),v.end(),[&](pair<int,int> i,pair<int,int> j){return b[i.first][i.second]<b[j.first][j.second];});
	for(int i=0;i<m;++i){
		ok[v[i].first][v[i].second]=1;
	}
	int now=0;
	for(int i=1;i<=n;++i){
		int tmp=now;
		int k=1;
		for(;k<=m&&tmp;++k){
			if(!ok[i][k])printf("%d ",b[i][k]),--tmp;
		}
		for(int j=1;j<=m;++j){
			if(ok[i][j])printf("%d ",b[i][j]),++now;
		}
		for(;k<=m;++k){
			if(!ok[i][k])printf("%d ",b[i][k]);
		}
		printf("\n");
	}
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}