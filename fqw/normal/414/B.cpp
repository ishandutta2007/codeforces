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

const int MOD=int(1e9)+7;
const int MAXN=2020;

int f[MAXN][MAXN];
int n, k;

void add(int &x, int y) {
	x+=y;
	if(x>=MOD) x-=MOD;
}

int main() {
	cin>>n>>k;
	fillchar(f, 0);
	forint(i, 1, n) f[1][i]=1;
	forint(i, 1, k-1) forint(j, 1, n) if(f[i][j]!=0)
		for(int j2=j; j2<=n; j2+=j)
			add(f[i+1][j2], f[i][j]);
	int ans=0;
	forint(j, 1, n) add(ans, f[k][j]);
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<endl;
	return 0;
}