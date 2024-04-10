#include <algorithm>
#include <iostream>
#include <cassert>
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
typedef pair<double,double> PDD;
typedef pair<int,int> PII;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<PII> VPI;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }


// ------------------------ template ends here ------------------------ //

struct Op {
	LL a, b; // multiply by (b/a)
	int i;
	Op(LL a, LL b, int i) : a(a), b(b), i(i) {}
	bool operator <(const Op &o) const {
		LL a1=a, b1=b;
		LL a2=o.a, b2=o.b;
		double g=double(b1)*a2-double(b2)*a1;
		if(abs(g)>1e10) return g<0;
		//b1+=a1, b2+=a2;
		LL t=b1*a2-b2*a1;
		if(t==0) t=i-o.i;
		return t<0;
	}
};

const int MAXN=100010;
const int MAXP=100010;

int pt[MAXP], pi[MAXP], pb[MAXP];
LL a[MAXN];
int p1[MAXN];
vector<PII> cx[MAXN];
int n, p, q;

set<Op> sx, sy;
void addx(int i) {
	if(cx[i].size()==0) return;
	PII cur=cx[i].back(); cx[i].pop_back();
	sx.insert(Op(a[i], a[i]+cur.fi, cur.se));
	//printf("addx i=%d (%d,%d,%d)\n",i,int(a[i]),int(a[i]+cur.fi),cur.se);
}

bool cmp(int i, int j) {
	return pt[i]<pt[j];
}

int main() {
	scanf("%d%d%d", &n,&p,&q);
	forint(i, 1, n) {
		int x; scanf("%d", &x);
		a[i]=x;
	}
	forint(i, 1, p)
		scanf("%d%d%d", pt+i, pi+i, pb+i);

	fillchar(p1, 0);
	forint(k, 1, p) if(pt[k]==1) {
		int i=pi[k];
		if(pb[k]<=a[i]) continue;
		if(p1[i]==0 || pb[k]>pb[p1[i]]) p1[i]=k;
	}
	forint(i, 1, n) cx[i].clear();
	forint(k, 1, p) if(pt[k]==2)
		cx[pi[k]].PB(MP(pb[k], k));
	forint(i, 1, n) if(p1[i]>0)
		cx[i].PB(MP(pb[p1[i]]-a[i], p1[i]));
	forint(i, 1, n)
		sort(all(cx[i]));
//printf("n=%d\n", n);
//forint(i, 1, n) printf("xn[%d]=%d\n", i,cx[i].size());

	sx.clear(); sy.clear();
	forint(i, 1, n) addx(i);
	forint(k, 1, p) if(pt[k]==3) sy.insert(Op(1, pb[k], k));

//printf("%d\n", sx.size());
	vector<int> ans;
	forn(_, q) {
		if(sx.size()>0 && (sy.size()==0 || *sy.rbegin()<*sx.rbegin())) {
			Op cur=*sx.rbegin();
			sx.erase(cur);
			ans.PB(cur.i);
			int i=pi[cur.i];
			assert(a[i]==cur.a);
			a[i]=cur.b;
			addx(i);
		} else {
			if(sy.size()==0)
				break;
			Op cur=*sy.rbegin();
			sy.erase(cur);
			ans.PB(cur.i);
		}
	}

	sort(all(ans), cmp);
	printf("%d\n", (int)ans.size());
	forn(i, ans.size()) printf("%d ", ans[_ i]);
	printf("\n");
	
	return 0;
}