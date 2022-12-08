// 22:15
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

const int MAXN=440;
const int INFI=1<<20;

int f[MAXN][MAXN], g[MAXN][MAXN];
int undefined_val;

int a[MAXN], w[MAXN];
int n;

int get_f(int i, int j);
int get_g(int i, int j);

int get_f(int i, int j) {
	int &ans=f[i][j];
	if(ans!=undefined_val) return ans;
	ans=-INFI;
	// case 1: a[i] and a[j] do not belong to the same seq
	forint(k, i, j-1)
		ans=max(ans, get_f(i, k) + get_f(k+1, j));
	// case 2: a[i] and a[j] are erased together; then enumerate center a[k]
	forint(k, i, j)
		if(a[i]<=a[k] && a[k]>=a[j]) {
			int len=(a[k]-a[i])+(a[k]-a[j])+1;
			if(len<=n)
				ans=max(ans, get_g(i, k) + get_g(k, j) + w[len]);
		}
	return ans;
}

int get_g(int i, int j) {
	int &ans=g[i][j];
	if(ans!=undefined_val) return ans;
	if(i==j) return ans=0;
	ans=-INFI;
	if(a[i]==a[j]) return ans;
	int next=(a[i]<a[j]?a[i]+1:a[i]-1);
	forint(k, i+1, j)
		if(a[k]==next) {
			int tmp=(i+1<=k-1 ? get_f(i+1, k-1) : 0) + get_g(k, j);
			ans=max(ans, tmp);
		}
	return ans;
}

int main() {
	cin>>n;
	forint(i, 1, n) cin>>w[i];
	forint(i, 1, n) cin>>a[i];

	fillchar(f, 99);
	fillchar(g, 99);
	undefined_val=f[0][0];

	int dp[MAXN];
	dp[0]=0;
	forint(i, 1, n) {
		dp[i]=dp[i-1];
		forint(j, 1, i)
			dp[i]=max(dp[i], dp[j-1]+get_f(j, i));
	}
	cout<<dp[n]<<endl;

	return 0;
}