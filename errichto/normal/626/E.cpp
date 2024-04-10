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
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

vi gen(int n, int high) {
	vi w;
	REP(_, n) w.pb(rand() % high);
	return w;
}

void te(int n) {
	vi w = gen(n, 10);
	sort(w.begin(), w.end());
	REP(i, n) {
		int memo = w[i];
		REP(j, n) w[j] -= memo;
		vector<ld> h;
		int a = i - 1, b = n - 1;
		int licznik = 0, mianownik = 1;
		h.pb(0);
		while(a >= 0 && b > i) {
			licznik += w[a] + w[b];
			mianownik += 2;
			h.pb((ld) licznik / mianownik);
			--a;
			--b;
		}
		bool juz = false;
		const ld eps = 1e-10;
		REP(j, sz(h) - 1) {
			ld diff = h[j+1] - h[j];
			if(juz) assert(diff < eps);
			if(diff < -eps) juz = true;
		}
		//for(ld x : h) printf("%Lf ", x); puts("");
		REP(j, n) w[j] += memo;
	}
}

int t[nax];
ll pref[nax];
int global_memo;

ll interval(int a, int b) {
	return pref[b] - (a ? pref[a-1] : 0) - (ll) global_memo * (b - a + 1);
}
ld find(int sr, int k, int n) {
	if(k == 0) return 0;
	assert(n - k > sr);
	assert(sr - k >= 0);
	ll licznik = interval(sr-k, sr-1) + interval(n - k, n - 1);
	return licznik / (ld) (2 * k + 1);
}

ld ans = -1;
int ans_sr, ans_k;
ld consider(int sr, int k, int n) {
	ld maybe = find(sr, k, n);
	if(maybe > ans) {
		// printf("%Lf %d %d\n", maybe, sr, k);
		ans = maybe;
		ans_sr = sr;
		ans_k = k;
	}
	return maybe;
}
#define find find_dont_use

int main() {
	// srand(42);
	// REP(_, 1000) te(105);
	int n;
	scanf("%d", &n);
	REP(i, n) scanf("%d", &t[i]);
	sort(t, t + n);
	//vector<pii> tmp;
	//REP(i, n) tmp.pb(mp(t[i], i));
	//sort(tmp.begin(), tmp.end());
	//REP(i, n) t[i] = tmp[i].st;
	REP(i, n) {
		pref[i] = t[i];
		if(i) pref[i] += pref[i-1];
	}
	REP(i, n) {
		global_memo = t[i];
		
		int low = 0, high = min(i, n - 1 - i);
		while(low < high - 6) {
			int x = (2LL * low + high) / 3;
			int y = (low + 2LL * high) / 3;
			if(consider(i, x, n) > consider(i, y, n))
				high = y;
			else 
				low = x;
		}
		FOR(k, low, high) consider(i, k, n);
		
	}
	vi write;
	write.pb(ans_sr);
	RI(i, ans_k) {
		write.pb(ans_sr - i);
		write.pb(n - i);
	}
	printf("%d\n", sz(write));
	for(int x : write) printf("%d ", t[x]);
	puts("");
	return 0;
}