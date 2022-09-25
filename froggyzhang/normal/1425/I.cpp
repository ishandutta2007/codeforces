#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native") 
#include<bits/stdc++.h>
using namespace std;
#define N 50050
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
int n,Q,a[N],_a[N],_dep[N],dep[N],_siz[N],f[N],t[N],A,B,T,dfn[N],num,id[N],siz[N];
vector<int> G[N];
void init(int u){
	dfn[u]=++num;
	_siz[u]=1;
	id[num]=u;
	_dep[u]=_dep[f[u]]+1;
	for(auto v:G[u])init(v),_siz[u]+=_siz[v];
}
int main(){
	n=read(),Q=read();
	for(int i=1;i<=n;++i){
		_a[i]=read();
	}
	for(int i=2;i<=n;++i){
		f[i]=read();
		G[f[i]].push_back(i);
	}
	init(1);
	for(int i=1;i<=n;++i){
		a[dfn[i]]=_a[i];
		dep[dfn[i]]=_dep[i];
		siz[dfn[i]]=_siz[i];
	}
	for(T=1;T<=Q;++T){
		int x=dfn[read()];
		A=B=0;
		int L=x,R=x+siz[x]-1;
		for(int i=L;i<=R;++i){
			if(t[i]<=T)++A,B+=dep[i],t[i]=T+a[i];
		}
		B-=A*dep[x];
		printf("%d %d\n",B,A);
	}
	return 0;
}