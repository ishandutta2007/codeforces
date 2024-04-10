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

const int MOD=1000000000+7;

int f[1010][1010];
int p[1010];
int n;

int main() {
	cin>>n; forint(i, 1, n) cin>>p[i];
	forint(j, 1, n+1) {
		f[j][j]=0;
		forintdown(i, j-1, 1)
			f[i][j]=(2+f[p[i]][i]+f[i+1][j])%MOD;
	}
	cout<<f[1][n+1]<<endl;
	return 0;
}