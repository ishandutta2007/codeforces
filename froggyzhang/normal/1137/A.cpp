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
int n,m,a[N][N],ra[N][N],rb[N][N],ca[N][N],cb[N][N],w[N];
void Solve(int n,int *w,int *a,int *b){
	static int len,c[N];
	for(int i=1;i<=n;++i){
		c[i]=w[i];	
	}	
	sort(c+1,c+n+1);
	len=unique(c+1,c+n+1)-c-1;
	for(int i=1;i<=n;++i){
		w[i]=lower_bound(c+1,c+len+1,w[i])-c;
		a[i]=w[i]-1;
		b[i]=len-w[i];
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			a[i][j]=read();
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			w[j]=a[i][j];
		}
		Solve(m,w,ra[i],rb[i]);
	}
	for(int j=1;j<=m;++j){
		for(int i=1;i<=n;++i){
			w[i]=a[i][j];
		}
		Solve(n,w,ca[j],cb[j]);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			printf("%d ",max(ca[j][i],ra[i][j])+max(cb[j][i],rb[i][j])+1);
		}
		printf("\n");
	}
	return 0;
}