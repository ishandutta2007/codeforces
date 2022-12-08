// 15:26
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

const LL MOD=LL(1e9)+7;
const int N=1010;
const int MAXN=1020;

LL fac[MAXN];
LL f[MAXN][MAXN], s[MAXN][MAXN];

int main() {
	fac[0]=1; forint(i, 1, N) fac[i]=fac[i-1]*i%MOD;

	fillchar(f, 0);
	fillchar(s, 0);
	f[0][0]=1;
	forint(i, 0, N) s[i][0]=1;
	forint(k, 1, N) {
		s[0][k]=0;
		forint(n, 1, N) {
			f[n][k]=0;
			for(int x=n; x>=1; --x) {
				int t=x-1-(k-1)*(n-x+1);
				if(t<0) break;
				(f[n][k]+=s[t][k-1]) %=MOD;
			}
			s[n][k]=(s[n-1][k]+f[n][k])%MOD;
		}
	}

	forint(n, 1, N) forint(k, 1, N) (s[n][k]*=fac[k]) %=MOD;

	int cs; cin>>cs;
	while(cs--) {
		int n, k; cin>>n>>k;
		cout<<s[n][k]<<endl;
	}
	return 0;
}