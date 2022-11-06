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
#define pct __builtin_popcount
#define N 1000010
#define mo 1000003
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
ll a[11][12];
int main(){
	rep(i,0,10){int x=1;
		rep(j,0,10)a[i][j]=x,x=x*i%mo;
		printf("? %d\n",i);fflush(stdout);
		scanf("%lld",&a[i][11]);
	}
	rep(i,0,10){
		dep(j,11,i)a[i][j]=a[i][j]*qk(a[i][i],mo-2)%mo;
		rep(j,i+1,10)dep(k,11,i)a[j][k]=(a[j][k]+mo-a[i][k]*a[j][i]%mo)%mo;
	}
	dep(i,10,0)dep(j,i-1,0){
		a[j][11]=(a[j][11]+mo-a[j][i]*a[i][11]%mo)%mo;a[j][i]=0;
	}
	rep(i,0,mo-1){ll s=0;
		rep(j,0,10)s=(s+qk(i,j)*a[j][11])%mo;
		if(!s){
			printf("! %d\n",i);fflush(stdout);return 0;
		}
	}
	printf("! -1\n");fflush(stdout);
}