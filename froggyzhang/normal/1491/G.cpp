#include<bits/stdc++.h>
using namespace std;
#define N 200020
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
int n,a[N],tot,vis[N];
vector<pair<int,int> > ans;
vector<int> g[N];
inline void Swap(int x,int y){
	ans.emplace_back(x,y);
	swap(a[x],a[y]);
	a[x]*=-1,a[y]*=-1;
}
void Solve1(vector<int> &A,vector<int> &B){
	Swap(A[0],B[0]);
	for(int i=1;i<(int)A.size();++i)Swap(A[i],B[0]);
	for(int i=1;i<(int)B.size();++i)Swap(B[i],A[0]);
	Swap(A[0],B[0]);
}
void Solve2(vector<int> &g){
	int sz=g.size();
	for(int i=2;i<sz;++i){
		Swap(g[0],g[i]);
	}
	Swap(g[0],g[1]);
	Swap(g[1],g[2]);
	Swap(g[0],g[2]);
}
int main(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i){
		if(a[i]==i)continue;
		if(vis[i])continue;
		++tot;
		for(int u=i;;u=a[u]){
			g[tot].push_back(u);
			vis[u]=1;
			if(a[u]==i)break;
		}
	}
	for(int i=1;i+1<=tot;i+=2){
		Solve1(g[i],g[i+1]);
	}
	if(tot&1){
		if(g[tot].size()==2){
			int p=1;
			while(p==g[tot][0]||p==g[tot][1])++p;
			Swap(p,g[tot][0]),Swap(p,g[tot][1]),Swap(p,g[tot][0]);
		}
		else{
			Solve2(g[tot]);
		}
	}
	printf("%d\n",(int)ans.size());
	for(auto [x,y]:ans){
		printf("%d %d\n",x,y);
	}
	return 0;
}