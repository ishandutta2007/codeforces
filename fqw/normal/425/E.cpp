#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <vector>
using namespace std;

#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<PII> VPI;
typedef pair<double,double> PDD;

const LL MOD=LL(1e9)+7;
const int MAXN=550;

LL f[MAXN][MAXN];

LL p2(LL x) {
	LL a=2, b=1;
	for(; x; x>>=1, a=(a*a)%MOD)
		if(x&1) b=(b*a)%MOD;
	return b;
}

int main() {
	int n, k; cin>>n>>k;
	memset(f, 0, sizeof(f));
	f[0][0]=1;
	forint(i, 0, n) forint(j, i+1, n) {
		LL t=p2((j-i)*i);
		(t*=p2(j-i)+MOD-1) %=MOD;
		forint(c, 0, i) {
			LL tmp=(f[i][c]*t)%MOD;
			(f[j][c+1]+=tmp) %=MOD;
		}
	}
	LL ans=0;
	forint(i, 0, n) {
		LL tmp=f[i][k];
		(tmp*=p2((n-i)*i)) %=MOD;
		(ans+=tmp) %=MOD;
	}
	//forint(i, 0, n) printf("f[%d][%d]=%I64d\n",i,k,f[i][k]);
	cout<<ans<<endl;

	return 0;
}