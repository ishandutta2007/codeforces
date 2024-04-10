#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
pll ans(LL a,LL b){
	//printf("%lld %lld\n",a,b);
	if(a==0||b==0)
	return mp(a,b);
	if(a>=2*b)
	return ans(a%(2*b),b);
	else if(b>=2*a)
	return ans(a,b%(2*a));
	return mp(a,b);
}
int main(){
	LL n,m;
	scanf("%lld %lld",&n,&m);
	pll p=ans(n,m);
	printf("%lld %lld\n",p.x,p.y);
}