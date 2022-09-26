#include<bits/stdc++.h>
using namespace std;
#define N 505
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
int n,m,a[N][N];
const int B=720720;
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			a[i][j]=read();
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if((i+j)&1)printf("%d ",B);
			else printf("%d ",B-a[i][j]*a[i][j]*a[i][j]*a[i][j]);
		}
		printf("\n");
	}
	return 0;
}