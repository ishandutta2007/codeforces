#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= (b); ++i)
#define FORD(i,a,b) for(int i = a; i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

set<int> s;
char sl[nax];

int f(int a, int b) {
	return max(0, b - a - 2);
}

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	scanf("%s", sl);
	REP(i, n) if(sl[i] != '.') s.insert(i);
	int prev = -1;
	s.insert(-1);
	s.insert(n);
	int r = 0;
	for(int a : s) {
		r += f(prev, a);
		prev = a;
	}
	//printf("%d\n", r);
	while(q--) {
		int i;
		char slo[4];
		scanf("%d%s", &i, slo);
		--i;
		if(slo[0] != '.') {
			auto it = s.lower_bound(i);
			if(it == s.end() || *it != i) {
				int nn = *it;
				--it;
				int pp = *it;
				r -= f(pp, nn);
				r += f(pp, i) + f(i,nn);
				s.insert(i);
			}
		}
		else {
			auto it = s.lower_bound(i);
			if(it != s.end() && *it == i) {
				++it;
				int nn = *it;
				--it; --it;
				int pp = *it;
				r -= f(pp,i) + f(i,nn);
				r += f(pp,nn);
				s.erase(i);
			}
		}
		printf("%d\n", r);
	}
	return 0;
}