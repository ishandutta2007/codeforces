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
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPI;
typedef pair<double,double> PDD;

const int MAXN=222;

int a[MAXN], n, k;

int main() {
	cin>>n>>k; forint(i, 1, n) cin>>a[i];
	int ans=-1<<30;
	forint(l, 1, n) forint(r, l, n) {
		VI x, y;
		forint(i, 1, n) if(i>=l && i<=r)
			x.PB(a[i]);
		else y.PB(a[i]);
		sort(x.begin(), x.end());
		sort(y.rbegin(), y.rend());
		int i=0, lim=min(k, (int)min(x.size(),y.size()));
		while(i<lim && x[i]<y[i]) swap(x[i],y[i]), ++i;
		int s=0; forn(i, x.size()) s+=x[i];
		ans=max(ans, s);
	}
	cout<<ans<<endl;
	return 0;
}