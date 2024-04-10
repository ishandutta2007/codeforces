#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 2000010
#define mo 998244353
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,m,a[N],f[N][3][5];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){int x;
		scanf("%d",&x);++a[x];
	}
	rep(i,0,m)rep(j,0,2)rep(k,0,4)f[i][j][k]=-inf;
	f[0][0][0]=0;
	rep(i,1,m){
		rep(j,0,2)rep(k,0,4){
			int t=min(a[i],min(j,k));
			rep(l,0,t){
				dep(s,(a[i]-l)/3,0){
					int *tt=&f[i][min(k-l,2)][min(a[i]-l-s*3,4)];
					*tt=max(*tt,f[i-1][j][k]+l+s);
					if(a[i]-l-s*3>3)break;
				}
			}
		}
		dep(j,2,0)dep(k,4,0){
			if(j<2)f[i][j][k]=max(f[i][j][k],f[i][j+1][k]);
			if(k<4)f[i][j][k]=max(f[i][j][k],f[i][j][k+1]);
		}
	}
	printf("%d\n",f[m][0][0]);
}