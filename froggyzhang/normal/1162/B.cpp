#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 55
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
int n,m,a[N][N],b[N][N],A[N][N],B[N][N];
bool check(){
	for(int i=1;i<=n;++i){
		for(int j=2;j<=m;++j){
			if(a[i][j]<=a[i][j-1])return false;
			if(b[i][j]<=b[i][j-1])return false;
		}
	}
	for(int i=2;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i][j]<=a[i-1][j])return false;
			if(b[i][j]<=b[i-1][j])return false;
		}
	}
	return true;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			A[i][j]=read();
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			B[i][j]=read();
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			a[i][j]=max(A[i][j],B[i][j]);
			b[i][j]=min(A[i][j],B[i][j]);
		}
	}
	if(check())return !printf("Possible\n");
	printf("Impossible\n");
	return 0;
}