// 14:52 - 15:19 sample
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

const int MAXN=300010;

struct Tri {
	int i, j, k;
	bool operator <(const Tri &t) const {
		return k<t.k;
	}
} d[MAXN];
int n, endpos;

void init() {
	static int a[MAXN], b[MAXN], c[MAXN];
	cin>>n;
	forint(i, 1, n) cin>>a[i];
	forint(i, 1, n) cin>>b[i];
	forint(i, 1, n) cin>>c[i];

	map<int,int> pa, pb, pc;
	set<int> numbers;
	forintdown(i, n, 1) numbers.insert(a[i]), pa[a[i]]=i;
	forintdown(i, n, 1) numbers.insert(b[i]), pb[b[i]]=i;
	forintdown(i, n, 1) numbers.insert(c[i]), pc[c[i]]=i;

	n=0;
	int tt=endpos=MAXN*3;
	for(set<int>::iterator it=numbers.begin(); it!=numbers.end(); ++it) {
		int x=*it;
		++n;
		if(pa.find(x)==pa.end()) d[n].i=++tt; else d[n].i=pa[x];
		if(pb.find(x)==pb.end()) d[n].j=++tt; else d[n].j=pb[x];
		if(pc.find(x)==pc.end()) d[n].k=++tt; else d[n].k=pc[x];
	}
}

struct Pair {
	int i, j;
	Pair(int i, int j) : i(i), j(j) {}
	bool operator <(const Pair &t) const {
		return i<t.i;
	}
};

set<Pair> seq;
multiset<int> ans;

void del(Pair p) {
	set<Pair>::iterator y=seq.lower_bound(p);
	set<Pair>::iterator x=y, z=y;
	--x, ++z;
	ans.erase(ans.find(x->i+y->j));
	ans.erase(ans.find(y->i+z->j));
	ans.insert(x->i+z->j);
	seq.erase(y);
}

void add(Pair p) {
	seq.insert(p);

	set<Pair>::iterator y=seq.lower_bound(p);
	set<Pair>::iterator x=y, z=y;
	--x, ++z;
	if(z->j>y->j) {
		seq.erase(p);
		return;
	}
	ans.insert(x->i+y->j);
	ans.insert(y->i+z->j);
	ans.erase(ans.find(x->i+z->j));

	while(1) {
		x=seq.lower_bound(p);
		--x;
		if(x->j<p.j) {
			del(*x);
		} else break;
	}
}

void solve() {
	sort(d+1, d+n+1);
	
	int ret=1<<30;
	seq.clear();
	seq.insert(Pair(0, 1<<28));
	seq.insert(Pair(1<<28, 0));
	ans.insert(0);
	
	int cur=n;
	while(cur>=1 && d[cur].k>=endpos) {
		add(Pair(d[cur].i, d[cur].j));
		--cur;
	}
	while(cur>=1) {
		ret=min(ret, *ans.begin()+d[cur].k);
		add(Pair(d[cur].i, d[cur].j));
		--cur;
	}
	ret=min(ret, *ans.begin());

	cout<<ret<<endl;
}

int main() {
	init();
	solve();
	return 0;
}