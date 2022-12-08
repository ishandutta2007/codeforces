#include <cstring>
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

const int MAXN=110;
const int MAXM=22;
const int MAXS=(1<<20)+10;

LL x[MAXN], k[MAXN]; int bits[MAXN];
int _b[MAXM];
int n, m; LL b;

LL f[2][MAXS];

int main() {
	cin>>n>>m>>b;
	_b[1]=1; forint(i, 2, m) _b[i]=_b[i-1]*2;
	forint(i, 1, n) {
		int t; cin>>x[i]>>k[i]>>t;
		bits[i]=0;
		while(t--) {
			int y; cin>>y;
			bits[i]|=_b[y];
		}
	}
	forint(i, 1, n) forint(j, i+1, n)
		if(k[i]<k[j]) {
			swap(x[i], x[j]);
			swap(k[i], k[j]);
			swap(bits[i], bits[j]);
		}
	int o1=0, o2=1;
	fillchar(f, 50); LL maxval=f[0][0];
	f[o1][0]=0;
	int all=(1<<m)-1;
	forint(i, 1, n) {
		fillchar(f[o2], 50);
		forn(st, all+1) {
			LL val=f[o1][st];
			setmin(f[o2][st], val);
			val+=x[i]; if(st==0) val+=b*k[i];
			setmin(f[o2][st|bits[i]], val);
		}
		swap(o1, o2);
	}
	if(f[o1][all]==maxval) cout<<-1<<endl;
		else cout<<f[o1][all]<<endl;
	return 0;
}