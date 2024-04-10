#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define _ (size_t)
#define all(a) a.begin(), a.end()
#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<double,double> PDD;
typedef pair<int,int> PII;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<PII> VPI;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }


// ------------------------ template ends here ------------------------ //

const LL MOD=LL(1e9)+7;
const int MAXN=100010;

LL m10[MAXN];
LL fac[MAXN], inv_fac[MAXN];

LL inv(LL a) {
	LL b=MOD-2, x=1;
	for(; b>0; b>>=1, a=a*a%MOD)
		if(b&1) x=x*a%MOD;
	return x;
}
LL binom(LL a, LL b) {
	if(a<0 || a>=MAXN) return 0;
	if(b<0 || b>=MAXN) return 0;
	if(b>a) return 0;
	return fac[a]*(inv_fac[b]*inv_fac[a-b]%MOD)%MOD;
}

int main() {
	m10[0]=1; forint(i, 1, MAXN-1) m10[i]=m10[i-1]*10%MOD;
	fac[0]=1; forint(i, 1, MAXN-1) fac[i]=fac[i-1]*i%MOD;
	forn(i, MAXN) inv_fac[i]=inv(fac[i]);
	//cout<<binom(5,2)<<endl;

	int k, n; scanf("%d%d", &n,&k);
	static char s[MAXN]; scanf("%s", s+1);
	static int a[MAXN]; forint(i, 1, n) a[i]=int(s[i]-'0');

	static LL f[MAXN];
	f[0]=0; forint(i, 1, MAXN-1) f[i]=(f[i-1]+m10[i-1]*binom(n-i-1,k-1))%MOD;

	LL ans=0;
	forint(i, 1, n) ans=(ans+binom(i-1,k)*a[i]%MOD*m10[n-i])%MOD;
	//cout<<binom(2,1)<<" "<<a[3]<<" "<<m10[0]<<endl;
	forint(i, 1, n) ans=(ans+a[i]*f[n-i])%MOD;
	cout<<ans<<endl;

	return 0;
}