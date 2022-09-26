#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 123
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
int T,n,m,a[N][N];
const int d[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
void Solve(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			a[i][j]=read();
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(((i+j)&1)^(a[i][j]&1))++a[i][j];
		}
	}
	for(int i=1;i<=n;++i,putchar('\n'))
		for(int j=1;j<=m;++j)
			printf("%d ",a[i][j]);
}
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		Solve();
	}
	return 0;
}