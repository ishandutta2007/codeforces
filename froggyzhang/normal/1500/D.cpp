#include<bits/stdc++.h>
using namespace std;
#define N 1505
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
vector<pair<int,int> > A[2][N],L[2][N],U[2][N];
int n,m,a[N][N],ans[N];
const pair<int,int> inf=make_pair(233333,233);
void calc(int x,int y){
	// L:
	L[x&1][y].emplace_back(1,a[x][y]);
	for(auto t:L[x&1][y-1]){
		if(t.second^a[x][y])L[x&1][y].emplace_back(t.first+1,t.second);	
	}
	if((int)L[x&1][y].size()>m+1)L[x&1][y].pop_back();
	// U:
	U[x&1][y].emplace_back(1,a[x][y]);
	for(auto t:U[(x-1)&1][y]){
		if(t.second^a[x][y])U[x&1][y].emplace_back(t.first+1,t.second);	
	}
	if((int)U[x&1][y].size()>m+1)U[x&1][y].pop_back();
	// A:
	static int vis[N*N];
	int i=0,j=0,k=0;
	A[x&1][y].emplace_back(1,a[x][y]);
	vis[a[x][y]]=1;
	while((int)A[x&1][y].size()<=m){
		while(i<(int)A[(x-1)&1][y-1].size()&&vis[A[(x-1)&1][y-1][i].second])++i;
		while(j<(int)L[x&1][y-1].size()&&vis[L[x&1][y-1][j].second])++j;
		while(k<(int)U[(x-1)&1][y].size()&&vis[U[(x-1)&1][y][k].second])++k;
		if(i==(int)A[(x-1)&1][y-1].size()&&j==(int)L[x&1][y-1].size()&&k==(int)U[(x-1)&1][y].size())break;
		auto tA=(i==(int)A[(x-1)&1][y-1].size()?inf:A[(x-1)&1][y-1][i]);
		auto tL=(j==(int)L[x&1][y-1].size()?inf:L[x&1][y-1][j]);
		auto tU=(k==(int)U[(x-1)&1][y].size()?inf:U[(x-1)&1][y][k]);
		auto mn=min(min(tA,tU),tL);
		if(mn==tA)A[x&1][y].emplace_back(tA.first+1,tA.second),++i;
		else if(mn==tL)A[x&1][y].emplace_back(tL.first+1,tL.second),++j;
		else if(mn==tU)A[x&1][y].emplace_back(tU.first+1,tU.second),++k;
		vis[A[x&1][y].back().second]=1;
	}
	for(auto t:A[x&1][y]){
		vis[t.second]=0;
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			a[i][j]=read();
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			A[i&1][j].clear();
			L[i&1][j].clear();
			U[i&1][j].clear();
		}
		for(int j=1;j<=n;++j){
			calc(i,j);
			++ans[1],--ans[min(min(i,j),(int)A[i&1][j].size()==m+1?A[i&1][j].back().first-1:n)+1];
		}
	}
	for(int i=1;i<=n;++i){
		ans[i]+=ans[i-1];
		printf("%d\n",ans[i]);
	}
	return 0;
}