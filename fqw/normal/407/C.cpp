#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPI;
#define MP make_pair
#define PB push_back
#define fi first
#define se second

const LL MOD=int(1e9)+7;
const int MAXN=100010;
const int MAXK=110;

LL b[MAXK][MAXN];
LL a[MAXN];
int n, q;

LL inv[MAXN];
LL pow(LL x, LL y) {
	LL ans=1;
	for(; y>0; y>>=1, x=x*x%MOD)
		if(y&1) ans=ans*x%MOD;
	return ans;
}

int main() {
	forint(i, 1, MAXN-1) inv[i]=pow(i, MOD-2);

	cin>>n>>q;
	forint(i, 1, n) cin>>a[i];
	fillchar(b, 0);
	while(q--) {
		int l, r, k; cin>>l>>r>>k;
		b[k][l]+=1;
		LL cur=1;
		forintdown(i, k, 0) {
			(b[i][r+1]-=cur)%=MOD;
			cur=cur*LL(r-l+k-i+1)%MOD;
			cur=cur*inv[k-i+1]%MOD;
		}
	}
	forint(i, 1, n) forintdown(k, MAXK-2, 0)
		b[k][i]=(b[k][i]+b[k][i-1]+b[k+1][i])%MOD;
	forint(i, 1, n) {
		a[i]=(a[i]+b[0][i])%MOD;
		a[i]=(a[i]+MOD)%MOD;
		cout<<a[i]<<" ";
	}
	cout<<endl;

	return 0;
}