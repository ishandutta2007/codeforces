// 11:54 - 12:09 - re sample
//       - 12:50 - wa 5
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

vector<PLL> nub(vector<PLL> a) {
	sort(all(a));
	vector<PLL> b;
	forn(i, a.size())
		if(b.size()==0 || b.back().fi!=a[_ i].fi)
			b.PB(a[_ i]);
	return b;
}

LL ex_gcd(LL a, LL b, LL &x, LL &y) {
	if(b==0) {
		x=1; y=0;
		return a;
	}
	LL g=ex_gcd(b, a%b, y, x);
	y-=a/b*x;
	return g;
}

LL get(LL n, LL m, LL i) {
	// return j that (jm)%n==i  | 0<=i<n, 0<=j<n
	LL a, b;
	// get am + bn == 1 
	// -> (ia)m + (ib)n == i
	// -> (ia)m == i (mod n)
	// -> j = (ia)%n
	ex_gcd(m, n, a, b);
	//cout<<"assert==1: "<<a*m+b*n<<endl;
	LL j=(i*a%n+n)%n;
	//cout<<"assert==: "<<"n="<<n<<" m="<<m<<" "<<i<<" "<<j<<" "<<j*m%n<<endl;
	return j;
}

LL go(LL n, LL m, VL a, VL b) {
	vector<PLL> v;
	forn(i, a.size()) v.PB(MP(a[_ i], a[_ i]));
	forn(i, b.size()) v.PB(MP(b[_ i]%n, b[_ i]));
	forn(i, v.size()) v[i].fi=get(n, m, v[i].fi);
	set<LL> s;
	forn(i, a.size()) s.insert(get(n, m, a[i]));
	v=nub(v);
	if(v.size()==0) return -2;

	forn(_, 2) forn(i, v.size()) {
		int j=(i+1)%v.size();
		LL delta=(v[j].fi-v[i].fi+n)%n;
		LL val=delta*m;
		setmin(v[j].se, v[i].se+val);
	}
	LL ans=-1;
	//forn(i, v.size()) setmax(ans, v[i].se);
	forn(i, v.size()) {
		int j=(i+1)%v.size();
		LL delta=(v[j].fi-v[i].fi+n-1)%n;
		if(s.find((v[i].fi+delta)%n)==s.end()) {
			LL val=delta*m;
			setmax(ans, v[i].se+val);
		//cout<<"  i="<<i<<" j="<<j<<" vi="<<v[i].fi<<" vj="<<v[j].fi<<" ("<<v[i].se<<")"<< " delta="<<delta <<" v="<<v[i].se+val<<endl;
		}
	}
	//cout<<"go "<<n<<" "<<m<<" na="<<a.size()<<" nb="<<b.size()<<" = "<<ans<<endl;
	return ans;
}

LL solve_1(LL n, LL m, VL a, VL b) {
	LL va=go(n, m, a, b);
	LL vb=go(m, n, b, a);
	if(va==-2 || vb==-2) return -2;
	return max(va, vb);
}

LL solve(LL n, LL m, VL a, VL b) {
	LL g=gcd(n, m);
	if(g>LL(a.size()+b.size()))
		return -1;
	vector<VL> ga(g), gb(g);
	forn(i, a.size()) ga[a[i]%g].PB(a[i]/g);
	forn(i, b.size()) gb[b[i]%g].PB(b[i]/g);
	LL ans=-1;
	forn(i, g) {
		LL tmp=solve_1(n/g, m/g, ga[i], gb[i]);
		if(tmp==-2) return -1;
		if(tmp>=0) {
			tmp=tmp*g+i;
			setmax(ans, tmp);
		}
	}
	return ans;
}

VL read_vec() {
	int n; scanf("%d", &n);
	VL v;
	forn(_, n) { int x; scanf("%d", &x); v.PB((LL)x); }
	return v;
}

int main() {
	int n, m;
	scanf("%d%d", &n,&m);
	VL a=read_vec();
	VL b=read_vec();
	LL ans=solve(n, m, a, b);
	cout<<ans<<endl;
	return 0;
}