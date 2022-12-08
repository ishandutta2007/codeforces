#include <cstring>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int,int> PII;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
template<class T> bool setmin(T &a, T b) {
	if(b<a) {a=b; return true;} else return false;
}
template<class T> bool setmax(T &a, T b) {
	if(b>a) {a=b; return true;} else return false;
}
#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define forn(i, n) for(int i=0; i<(int)(n); ++i)
#define forndown(i, n) for(int i=(int)(n)-1; i>=0; --i)
#define fillchar(a, x) memset(a, x, sizeof(a))

const int MOD=1000000000+7;
const int MAXN=100010;

LL fac[MAXN];
int n;
int a[MAXN];

LL inv(LL a) {
	LL ans=1;
	for(int b=MOD-2; b>0; b>>=1, a=a*a%MOD)
		if(b&1) ans=ans*a%MOD;
	return ans;
}

LL C(int a, int b) {
	if(b<0 || b>a) return 0;
	LL ans=fac[a];
//printf("fac=%lld inv_fac=%lld mul=%lld\n",fac[a],inv(fac[a]),fac[a]*inv(fac[a])%MOD);
	ans=ans*inv(fac[b])%MOD;
	ans=ans*inv(fac[a-b])%MOD;
//printf("C(%d,%d)=%lld\n",a,b,ans);
	return ans;
}

int nxt[MAXN], lst[MAXN];

LL comp_l(int le, int ri) {
	int n=ri-le+1;
	if(n<=0) return 0;
	int pl=nxt[le]; if(pl>ri) pl=0;
	int pr=lst[ri]; if(pr<le) pr=0;
	LL ans=0;
	if(pl==0 && pr==0) {
		ans=1;
		forint(i, 1, n-1) ans=ans*2%MOD;
		return ans;
	}
	assert(pl>0 && pr>0);
	if(pl==le)
		return 0;
	int x=ri-pr, y=pl-le;
	int c=n-a[pr];
	//printf("R le=%d ri=%d pl=%d pr=%d x=%d y=%d c=%d\n",le,ri,pl,pr,x,y,c);
	if(c>=x && c<=x+y)
		ans+=C(c, x)*comp_l(le+(c-x), ri-(x+1))%MOD;
	return ans;
}

LL comp_r(int le, int ri) {
	int n=ri-le+1;
	if(n<=0) return 0;
	int pl=nxt[le]; if(pl>ri) pl=0;
	int pr=lst[ri]; if(pr<le) pr=0;
	LL ans=0;
	if(pl==0 && pr==0) {
		ans=1;
		forint(i, 1, n-1) ans=ans*2%MOD;
		return ans;
	}
	assert(pl>0 && pr>0);
	if(pr==ri)
		return 0;
	int x=pl-le, y=ri-pr;
	int c=n-a[pl];
	//printf("L le=%d ri=%d pl=%d pr=%d x=%d y=%d c=%d\n",le,ri,pl,pr,x,y,c);
	if(c>=x && c<=x+y)
		ans+=C(c, x)*comp_r(le+(x+1), ri-(c-x))%MOD;
	return ans;
}

LL comp(int le, int ri) {
	int n=ri-le+1;
	int pl=nxt[le]; if(pl>ri) pl=0;
	int pr=lst[ri]; if(pr<le) pr=0;
	LL ans=0;
	if(pl==0 && pr==0) {
		ans=1;
		forint(i, 1, n-1) ans=ans*2%MOD;
		return ans;
	}
	assert(pl>0 && pr>0);
	if(a[pl]>a[pr]) {
		int x=pl-le, y=ri-pr;
		int c=n-a[pl];
		//printf("L le=%d ri=%d pl=%d pr=%d x=%d y=%d c=%d\n",le,ri,pl,pr,x,y,c);
		if(c>=x && c<=x+y)
			ans+=C(c, x)*comp(le+(x+1), ri-(c-x))%MOD;
//printf("#1 ans=%lld\n", ans);
		ans+=comp_l(le, ri);
//printf("#2 ans=%lld\n", ans);
	} else {
		int x=ri-pr, y=pl-le;
		int c=n-a[pr];
		//printf("R le=%d ri=%d pl=%d pr=%d x=%d y=%d c=%d\n",le,ri,pl,pr,x,y,c);
		if(c>=x && c<=x+y)
			ans+=C(c, x)*comp(le+(c-x), ri-(x+1))%MOD;
//printf("#1 ans=%lld\n", ans);
		ans+=comp_r(le, ri);
//printf("#3 ans=%lld\n", ans);
	}
	return ans;
}

LL solve() {
	fac[0]=1;
	forint(i, 1, n) fac[i]=fac[i-1]*i%MOD;

	nxt[n+1]=0;
	forintdown(i, n, 1) {
		nxt[i]=nxt[i+1];
		if(a[i]>0) nxt[i]=i;
	}
	lst[0]=0;
	forint(i, 1, n) {
		lst[i]=lst[i-1];
		if(a[i]>0) lst[i]=i;
	}
	LL ans=comp(1, n);
	ans=(ans%MOD+MOD)%MOD;
	return ans;
}


LL vio_ans;
int t[MAXN];
LL vio() {
	vio_ans=0;
	forint(i, 1, n) t[i]=i;
	do {
		bool flag=true;
		forint(i, 1, n) {
			if(a[i]>0 && t[i]!=a[i]) flag=false;
			if(i>1 && i<n) {
				if(t[i-1]<t[i] && t[i+1]>t[i]) flag=false;
			}
		}
		if(flag) ++vio_ans;
	} while(next_permutation(t+1, t+n+1));
	return vio_ans;
}

int main() {
	scanf("%d", &n); forint(i, 1, n) scanf("%d", &a[i]);
	LL ans=solve();
	printf("%d\n", (int)ans);
	/*
	srand(123456789);
	for(int cs=1; ; ++cs) {
		n=2;
		forint(i, 1, n) a[i]=i;
		forint(i, 2, n) swap(a[i], a[rand()%i+1]);
		forint(i, 1, n) if(rand()%4!=0) a[i]=0;
		LL std=vio();
		LL ans=solve();
		if(std==ans) printf("yes. %lld\n", std);
		else {
			printf("error! std=%lld ans=%lld\n",std,ans);
			forint(i, 1, n) printf("%d ", a[i]); printf("\n");
			for(;;);
		}
	}
	*/
	return 0;
}