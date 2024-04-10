// 15:40
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

const int MAXN=5050;

int a[MAXN];
int g[MAXN], wg[MAXN];
set<int> bad;
int n;

int gcd(int a, int b) {
	return b==0 ? a : gcd(b,a%b);
}

int pw(int x) {
	return bad.find(x)!=bad.end() ? 1 : -1;
}

int cal_w(int x) {
	int ans=0;
	for(int y=2; y*y<=x; ++y)
		while(x%y==0) {
			ans+=pw(y);
			x/=y;
		}
	if(x>1) ans+=pw(x);
	return ans;
}

int f[MAXN];

int main() {
	int m;
	cin>>n>>m; forint(i, 1, n) cin>>a[i];
	bad.clear();
	while(m--) {
		int x; cin>>x;
		bad.insert(x);
	}
	int ans=0;
	forint(i, 1, n) ans-=cal_w(a[i]);

	g[1]=a[1];
	forint(i, 2, n) g[i]=gcd(g[i-1], a[i]);
	g[n+1]=1;
	wg[n+1]=0;
	forintdown(i, n, 1)
		wg[i]=wg[i+1]+cal_w(g[i]/g[i+1]);
	
	f[n+1]=0;
	forintdown(i, n, 1) {
		f[i]=-(1<<30);
		forint(j, i+1, n+1)
			f[i]=max(f[i], f[j]+(wg[i]-wg[j])*i);
	}
	int addi=0;
	forint(i, 1, n) addi=max(addi, f[i]);
	ans+=addi;
	cout<<ans<<endl;
	
	return 0;
}