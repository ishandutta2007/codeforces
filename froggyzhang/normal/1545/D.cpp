#include<bits/stdc++.h>
using namespace std;
#define N 1010
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
int n,m,A,B,v1,v2,a[N][N],g[N];
int Get_v2(int p){
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			g[i]+=a[i][j]*a[i][j];
		}	
	}
	++p;
	return (g[p+1]+g[p-1]-(g[p]<<1))/2;
}
void calc(int x,int sum){
	for(int j=1;j<=n;++j){
		int nw=a[x][j]+v1*(x-1)+A-sum;
		int t=g[x]-a[x][j]*a[x][j]+nw*nw;
		if((g[x+1]+g[x-1]-(t<<1))/2==v2){
			printf("%d %d\n",x-1,nw);
			return;
		}	
	}	
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			a[i][j]=read();
		}
	}
	for(int j=1;j<=n;++j)A+=a[1][j],B+=a[m][j];
	v1=(B-A)/(m-1);
	for(int i=2;i<m;++i){
		int sum=0;
		for(int j=1;j<=n;++j){
			sum+=a[i][j];
		}
		if(sum-A!=v1*(i-1)){
			v2=Get_v2(i<4?i+1:1);
			calc(i,sum);
			return 0;
		}
	}
	return 0;
}