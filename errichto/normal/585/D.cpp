#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef long long ll;
typedef vector<ll> vi;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 2e9 + 5;
const int nax = 1e6 + 5;

int a[nax], b[nax], c[nax];

void rec(int i, int high, int A, int B, int C, vector<vi> & w, ll mask) {
	if(i > high) {
		w.pb(vi{A,B,C,mask});
		return;
	}
	rec(i+1, high, A+a[i], B+b[i], C, w, 3*mask+2);
	rec(i+1, high, A, B+b[i], C+c[i], w, 3*mask+0);
	rec(i+1, high, A+a[i], B, C+c[i], w, 3*mask+1);
}

vector<vi> three(int low, int high) {
	vector<vi> w;
	rec(low, high, 0, 0, 0, w, 0LL);
	return w;
}

vi anti(ll mask, int n) {
	vi w;
	REP(_, n) {
		w.pb(mask % 3);
		mask /= 3;
	}
	reverse(w.begin(), w.end());
	return w;
}

int main() {
	int n;
	scanf("%d", &n);
	REP(i, n) scanf("%d%d%d", &a[i], &b[i], &c[i]);
	int half = n / 2;
	vector<vi> one = three(0, half - 1);
	vector<vi> two = three(half, n-1);
	map<pii,pair<int,ll>> s;
	for(vi & w : one) {
		int A = w[0], B = w[1], C = w[2];
		ll mask = w[3];
		pii p = mp(B-A, C-A);
		if(s.count(p)) maxi(s[p], make_pair(A,mask));
		else s[p] = make_pair(A,mask);
	}
	pair<int,pair<ll,ll> > res = make_pair(-inf, mp(0LL,0LL));
	for(vi & w : two) {
		int A = w[0], B = w[1], C = w[2];
		ll mask = w[3];
		pii p = mp(A-B, A-C);
		if(s.count(p)) {
pair<int,ll> fast = s[p];
maxi(res, make_pair(A + fast.st, make_pair(fast.nd, mask)));
}
	}
	if(res.st == -inf) {
		puts("Impossible");
		return 0;
	}
	vi w = anti(res.nd.st, half);
	vi t = anti(res.nd.nd, n - half);
	for(int a : t) w.pb(a);
	for(int a : w) {
		if(a == 0) puts("MW");
		else if(a == 1) puts("LW");
		else if(a == 2) puts("LM");
		else assert(false);
	}
	return 0;
}