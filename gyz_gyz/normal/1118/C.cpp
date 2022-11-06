#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 1010
#define mo 1000000007
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int a[N][N],b[N];
int main(){
	int n,t=1,x=1,y=1;
	scanf("%d",&n);
	rep(i,1,n*n){int x;
		scanf("%d",&x);++b[x];
	}
	rep(i,1,1000){
		if(b[i]&1){
			if((n&1)&&!a[n/2+1][n/2+1]){
				a[n/2+1][n/2+1]=i;--b[i];
			}else return printf("NO\n"),0;
		}
		if(b[i]&2){
			if((n&1)&&t<n){
				if(t<=n/2)a[t][n/2+1]=a[n-t+1][n/2+1]=i;
				else a[n/2+1][t+1]=a[n/2+1][n-t]=i;
				b[i]-=2;++t;
			}else return printf("NO\n"),0;
		}
	}
	printf("YES\n");
	rep(i,1,1000){
		while(b[i]&&(n&1)&&t<n){
			if(t<=n/2)a[t][n/2+1]=a[n-t+1][n/2+1]=i;
			else a[n/2+1][t+1]=a[n/2+1][n-t]=i;
			b[i]-=2;++t;
		}
		while(b[i]){
			while(a[x][y]){
				++y;if(y>n)y=1,++x;
			}
			a[x][y]=a[n-x+1][y]=a[x][n-y+1]=a[n-x+1][n-y+1]=i;b[i]-=4;
		}
	}
	rep(i,1,n){
		rep(j,1,n)printf("%d ",a[i][j]);printf("\n");
	}
}