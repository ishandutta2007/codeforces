#include <cstdlib>
#include <set>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

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
typedef pair<int,int> PII;
typedef vector<PII> VPI;
typedef pair<double,double> PDD;

const int MAXN=100010*2;

PII color[MAXN];
int n, num;

multiset<pair<PII,int> > s;

void merge(pair<PII,int> a, pair<PII,int> b) {
	if(a.fi.se==b.fi.se) {
		color[a.se]=MP(0, 0);
		color[b.se]=MP(0, 1);
	} else {
		++num;
		int l=min(a.fi.se, b.fi.se)+1;
		int r=max(a.fi.se, b.fi.se);
		s.insert(MP(MP(l,r), num));
		if(a.fi.se>b.fi.se) {
			color[a.se]=MP(num, 0);
			color[b.se]=MP(-num, 0);
		} else {
			color[a.se]=MP(-num, 0);
			color[b.se]=MP(num, 0);
		}
	}
}

int main() {
	s.clear();
	scanf("%d", &n);
	num=n;
	forint(i, 1, n) {
		int l, r; scanf("%d%d", &l,&r);
		s.insert(MP(MP(l,r), i));
	}
	while(s.size()>0) {
		pair<PII,int> a=*s.begin(); s.erase(s.begin());
		if(s.size()==0) {
			color[a.se]=MP(0,0);
			continue;
		}
		pair<PII,int> b=*s.begin(); s.erase(s.begin());
		if(s.size()>0) {
			pair<PII,int> c=*s.begin(); s.erase(s.begin());
			if(b.fi.fi==c.fi.fi) {
				merge(b, c);
				s.insert(a);
				continue;
			}
			s.insert(c);
		}
		merge(a, b);
	}
	forintdown(i, num, 1)
		if(color[i].fi!=0) {
			if(color[i].fi>0) color[i].se=color[color[i].fi].se;
				else color[i].se=1-color[-color[i].fi].se;
		}
	forint(i, 1, n) printf("%d ", color[i].se); printf("\n");
	return 0;
}