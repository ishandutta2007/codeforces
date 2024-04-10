#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int loca[1000005],locb[1000005];
LL r[1000005];
pll gcd(LL a, LL b){
    if(b == 0) return mp(1, 0);
    else{
        LL p = a / b;
        pll q = gcd(b, a % b);
        return make_pair(q.y, q.x - q.y * p);
    }
}

LL solve(LL x1, LL m1, LL x2, LL m2){
    LL g = __gcd(m1, m2);
    if((x2 - x1) % g)return -1;
    m1 /= g; m2 /= g;
    pll p = gcd(m1, m2);
    LL lcm = m1 * m2 * g;
    LL res = p.x * (x2 - x1) * m1 + x1;
    return (res % lcm + lcm) % lcm;
}
bool solve(){
	int n,m;
	LL k;
	scanf("%d %d %lld",&n,&m,&k);
	MEMS(loca);
	MEMS(locb);
	for(int i = 0;i<n;i++){
		int x;
		scanf("%d",&x);
		loca[x]=i;
	}
	for(int i = 0;i<m;i++){
		int x;
		scanf("%d",&x);
		locb[x]=i;
	}
	for(int i = 1;i<=1000000;i++){
		if(loca[i]!=-1&&locb[i]!=-1){
		//	printf("%d\n",i);
			r[i]=solve(loca[i],n,locb[i],m);
		}
		else{
			r[i]=-1;
		}
	}
	LL Min=-1,Max=1e18;
	LL aa=n*1ll*m/__gcd(n,m);
	while(Max>Min+1){
		LL mid=(Max+Min)/2;
		LL tot=mid;
		for(int i = 1;i<=1000000;i++){
			if(r[i]!=-1&&mid>r[i]){
				tot-=(mid-r[i]-1)/aa+1;
			}
		}
		//if(mid<100)printf("%lld %lld\n",mid,tot);
		if(tot>=k)Max=mid;
		else Min=mid;
	}
	printf("%lld\n",Max);
}
int main(){
	int t=1;
   
	while(t--)solve();
}