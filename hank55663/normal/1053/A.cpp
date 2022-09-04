#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
	LL n,m,k;
	scanf("%lld %lld %lld",&n,&m,&k);
	LL x=n;
	LL gcd=__gcd(x,k);
	x/=gcd;
	k/=gcd;
	LL y=m;
	gcd=__gcd(y,k);
	y/=gcd;
	k/=gcd;
	if(k==2){
		printf("YES\n");
		printf("0 0\n");
		printf("%lld 0\n",x);
		printf("0 %lld\n",y);
	}
	else if(k==1){
		if(x*2<=n)
		x*=2;
		else if(y*2<=m)
		y*=2;
		else{
			printf("NO\n");
			return 0;
		}
		printf("YES\n");
		printf("0 0 \n");
		printf("%lld 0\n",x);
		printf("0 %lld\n",y);
	}
	else{
		printf("NO\n");
	}
}