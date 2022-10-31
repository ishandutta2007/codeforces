#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define all(c) (c).begin(), (c).end()
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
 
const int N = 5001;
 
vi primes;
int cnt[N];
vector<pair<int, int>> pCnt[N];
ll cntP[N];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	forn(i, n) {
		int k;
		cin >> k;
if(k==0)k++;
		cnt[k]++;
	}
 
	forab(i, 2, N) {
		int ok = 1;
		forab(j, 2, i) {
			if (i % j == 0) {
				ok = 0;
				break;
			}
		}
		if (ok) primes.pb(i);
	}
	ll totalCnt = 0;
	vector<int> indices;
	for (int v = 1; v <= 5000; v++) {
		if (cnt[v] == 0) continue;
		
		for(int p : primes) {
			int cur = p;
			int cntCur = 0;
			while(cur <= v) {
				cntCur += v / cur;
				cur *= p;
			}
			if (cntCur) {
				pCnt[v].pb(mp(p, cntCur));
				totalCnt += cntCur * 1ll * cnt[v];
			}
		}
		if (v != 1)	indices.pb(v);
	}
	//cout << totalCnt << '\n';
	int cntLast = cnt[1];
	while(1) {
	//	cerr << "!";
		for(int p : primes) cntP[p] = 0;
		int cntDown = 0;
		for(int v : indices) {
	//		cerr << v << '\n';
	//		cerr << pCnt[v].back().fst << " " << pCnt[v].back().snd << '\n';
			cntP[pCnt[v].back().fst] += cnt[v];
			cntDown += cnt[v];
		}
		int best = -1;
		ll deltaBest = 0;
		for(int p : primes) {
			if (2 * cntP[p] - cntLast - cntDown > deltaBest) {
				deltaBest = 2 * cntP[p] - cntLast - cntDown;
				best = p;
			}
		}
		//cerr << best << " " << deltaBest << '\n';
		if (best == -1) break;
		vector<int> indicesNew;
		totalCnt -= deltaBest;
		cntLast += cntDown - cntP[best];
 
		for(int v : indices) {
			if (pCnt[v].back().fst != best) continue;
			pCnt[v].back().snd--;
			while(!pCnt[v].empty() && pCnt[v].back().snd == 0) pCnt[v].pop_back();
			if (!pCnt[v].empty()) {
				indicesNew.pb(v);
			} else {
				cntLast += cnt[v];
			}
		}
		indices = indicesNew;
		
	}
	cout << totalCnt << '\n';
    return 0;
}