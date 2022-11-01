#include<bits/stdc++.h>
using namespace std;
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
int T,n,m;
int a[30][30];
inline bool check(int x,int y){
	for(int i=-1;i<=1;++i){
		for(int j=-1;j<=1;++j){
			if(a[x+i][y+j])return false;
		}
	}
	return true;
}
void Solve(){
	n=read(),m=read();
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;++i){
		if(check(i,1))a[i][1]=1;	
	}
	for(int j=1;j<=m;++j){
		if(check(n,j))a[n][j]=1;
	}
	for(int i=n;i>=1;--i){
		if(check(i,m))a[i][m]=1;
	}
	for(int j=m;j>=1;--j){
		if(check(1,j))a[1][j]=1;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
		printf("%d",a[i][j]);
	}
		printf("\n");
	}
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}