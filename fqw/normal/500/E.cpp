// 11:04 - 11:16 - sample
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define _ (size_t)
#define all(a) a.begin(), a.end()
#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }


// ------------------------ template ends here ------------------------ //
const int MAXN=200010;
LL p[MAXN], r[MAXN];
int far[MAXN];
int n;
const int MAXQ=200010;
int qx[MAXQ], qy[MAXQ];
vector<PII> qs;
LL ans[MAXQ];
int m;

LL gap[MAXN];
LL tr[MAXN];
void add(int x, LL v) {
	for(; x<=n; x+=(x&-x)) tr[x]+=v;
}
LL get(int x) {
	LL ans=0;
	for(; x>=1; x-=(x&-x)) ans+=tr[x];
	return ans;
}

int nxt[MAXN];
int get_nxt(int x) {
	return nxt[x]==x ? x : nxt[x]=get_nxt(nxt[x]);
}

int main() {
	scanf("%d", &n);
	forint(i, 1, n) {
		int x, l; scanf("%d%d", &x,&l);
		p[i]=x, r[i]=x+l;
	}
	forint(i, 1, n)
		far[i]=int(upper_bound(p+i, p+n+1, r[i])-p)-1;
	scanf("%d", &m);
	qs.clear();
	forint(i, 1, m) {
		scanf("%d%d", &qx[i], &qy[i]);
		qs.PB(MP(qx[i], i));
	}
	sort(all(qs));
	
	fillchar(tr, 0);
	fillchar(gap, 0);
	forint(i, 1, n+1) nxt[i]=i;
	forintdown(i, n-1, 1) {
		gap[i]=p[i+1]-p[i];
		add(i, gap[i]);
		int j=far[i];
		for(int k=get_nxt(i); k<j; nxt[k]=k+1, k=get_nxt(k)) {
			add(k, -gap[k]);
			gap[k]=0;
		}
		if(j<n) {
			LL tmp=p[j+1]-r[i];
			if(tmp<gap[j]) {
				add(j, tmp-gap[j]);
				gap[j]=tmp;
			}
		}
		while(qs.size()>0 && qs.back().fi==i) {
			int k=qs.back().se;
			qs.pop_back();
			ans[k]=get(qy[k]-1);
		}
	}
	forint(i, 1, m)
		cout<<ans[i]<<endl;
	
	return 0;
}