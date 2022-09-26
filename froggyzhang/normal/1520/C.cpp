#include<bits/stdc++.h>
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
int T,n,a[N][N];
inline bool check(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i<n&&abs(a[i+1][j]-a[i][j])==1)return false;
			if(j<n&&abs(a[i][j+1]-a[i][j])==1)return false;
		}
	}
	return true;
}
mt19937 rnd(time(0));
void Solve(){
	static int p[N*N];
	n=read();
	if(n==2){
		printf("-1\n");
		return;
	}
	for(int i=1;i<=n*n;++i)p[i]=i;
	do{
		shuffle(p+1,p+n*n+1,rnd);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				a[i][j]=p[(i-1)*n+j];
			}
		}
	}while(!check());
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			printf("%d ",a[i][j]);
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