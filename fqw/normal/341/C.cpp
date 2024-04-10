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
#define fillchar(a, x) memset(a, (x), sizeof(a))

const LL MOD=1000000000+7;
const int MAXN=2010;

int a[MAXN]; int n;
int b[MAXN];
int ra[MAXN], rb[MAXN];

LL f[MAXN][MAXN];

int main() {
	scanf("%d", &n); forint(i, 1, n) scanf("%d", a+i);

	fillchar(b, 0xff);
	forint(i, 1, n) if(a[i]>0) b[a[i]]=i;
	ra[0]=rb[0]=0;
	forint(i, 1, n) {
		ra[i]=ra[i-1]; if(a[i]<0) ++ra[i];
		rb[i]=rb[i-1]; if(b[i]<0) ++rb[i];
	}
	fillchar(f, 0);
	f[0][0]=1;
	forint(i, 0, n-1) forint(j, 0, i) {
		LL v=f[i][j];
		f[i+1][j]=(f[i+1][j]+v)%MOD;
		if(a[i+1]<0) f[i+1][j+1]=(f[i+1][j+1]+v*(rb[i]-j))%MOD;
		if(b[i+1]<0) f[i+1][j+1]=(f[i+1][j+1]+v*(ra[i]-j))%MOD;
		if(a[i+1]<0 && b[i+1]<0) f[i+1][j+2]=(f[i+1][j+2]+v*(ra[i]-j)%MOD*(rb[i]-j))%MOD;
		//printf("f[%d][%d]=%lld\n",i,j,f[i][j]);
	}
	LL ans=f[n][ra[n]];
	cout<<ans<<endl;
	return 0;
}