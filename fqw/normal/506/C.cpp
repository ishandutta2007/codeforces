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
typedef pair<double,double> PDD;
typedef pair<int,int> PII;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<PII> VPI;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }


// ------------------------ template ends here ------------------------ //
const int MAXN=100000;

LL h[MAXN], a[MAXN];
int n, m, k; LL p, X;

int t[MAXN];

int calc_neg_day(int i) {
	LL d=(X+t[i]*p+1  +a[i]-1)/a[i];
	LL ans=m-d;
	if(ans>=0) return (int)ans;
		else return -1;
}
bool check_ok(int i) {
	LL c=X+t[i]*p-a[i]*m;
	return c>=h[i];
}

bool ok(LL _X) {
	X=_X;
	fillchar(t, 0);
	set<PII, greater<PII> > set_neg;
	set<int> set_h;
	forn(i, n) {
		int d=calc_neg_day(i);
		if(d>=0) set_neg.insert(MP(d, i));
		else {
			if(!check_ok(i)) set_h.insert(i);
		}
	}
	forintdown(day, m-1, 0) {
	//printf("day=%d\n",day);
		if(set_neg.size()>0) {
			if(set_neg.begin()->fi>=day) // it has became neg
				return false;
		}
		forn(_, k) {
			if(set_neg.size()>0) {
				int i=set_neg.begin()->se;
				set_neg.erase(set_neg.begin());
				++t[i];
				int d=calc_neg_day(i);
				if(d>=0) set_neg.insert(MP(d, i));
				else if(!check_ok(i)) set_h.insert(i);
			} else if(set_h.size()>0) {
				int i=*set_h.begin();
				set_h.erase(set_h.begin());
				++t[i];
				if(!check_ok(i)) set_h.insert(i);
			}
		}
	}
	return set_neg.size()==0 && set_h.size()==0;
	//forn(i, n) if(!check_ok(i)) return false;
	//return true;
}

int main() {
	int _p; scanf("%d%d%d%d", &n,&m,&k,&_p); p=_p;
	forn(i, n) {
		int _h, _a; scanf("%d%d", &_h,&_a);
		h[i]=_h, a[i]=_a;
	}
	LL le=0, ri=LL(1e9 * 1e4);
	while(le<ri) {
		LL mid=(le+ri)/2;
		if(ok(mid))
			ri=mid;
		else
			le=mid+1;
	}
	cout<<le<<endl;
	return 0;
}