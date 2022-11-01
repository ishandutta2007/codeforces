#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int br_hash = 10;
const int mod = 1e9 + 7;

unordered_map <int, int> mape [br_hash];

int add(int a, int b) {
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
	return a;
}

int mult(int a, int b) {
	return (ll) a * b % mod;
}

int main() {
	srand(time(NULL));
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> niz(n);
	vector <int> hash [br_hash][2];
	vector <int> cnt(n, 0);
	REP(i, br_hash) {
		hash[i][0].resize(n);
		hash[i][1].resize(n);
		REP(j, n) {
			hash[i][0][j] = add(mult(rand() % mod, rand() % mod), rand() % mod);
			hash[i][1][j] = add(mult(rand() % mod, rand() % mod), rand() % mod);
		}
	}
	int tr_suma[br_hash];
	int dod[br_hash];
	ll rj[br_hash];
	REP(i, br_hash) {tr_suma[i] = 0; rj[i] = 0; mape[i][0] = 1;}
	vector <int> sume[br_hash];
	vector <int> br_ind[n];
	REP(i, br_hash) sume[i].resize(n);
	int do_kud = 0;
	bool poceo = 0;
	REP(i, n) {
		cin >> niz[i];
		niz[i]--;
		br_ind[niz[i]].push_back(i);
		if(br_ind[niz[i]].size() >= 4) {
			if(!poceo) {
				poceo = 1;
				REP(j, br_hash) mape[j][0]--;
			}
			int kr = br_ind[niz[i]][br_ind[niz[i]].size() - 4];
			while(do_kud < kr) {
				REP(j, br_hash) {
					mape[j][sume[j][do_kud]]--;
				}
				do_kud++;
			}
		}
		if(cnt[niz[i]] == 0) {
			REP(j, br_hash) dod[j] = hash[j][0][niz[i]];
			cnt[niz[i]] = 1;
		}
		else if(cnt[niz[i]] == 1) {
			REP(j, br_hash) dod[j] = hash[j][1][niz[i]];
			cnt[niz[i]] = 2;
		}
		else {
			REP(j, br_hash) dod[j] = add(add(mod, -hash[j][0][niz[i]]), -hash[j][1][niz[i]]);
			cnt[niz[i]] = 0;
		}
		REP(j, br_hash) {
			tr_suma[j] = add(tr_suma[j], dod[j]);
			sume[j][i] = tr_suma[j];
			int trazi = tr_suma[j];
			rj[j] += mape[j][trazi];
			mape[j][tr_suma[j]]++;
		}
		vector <pair <int, ll> > svi;
		svi.push_back(make_pair(1, rj[0]));
		for(int j = 1; j < br_hash; j++) {
			bool nasao = 0;
			REP(k, (int)svi.size()) {
				if(svi[k].second == rj[j]) {
					nasao = 1;
					svi[k].first++;
				}
			}
			if(!nasao) svi.push_back(make_pair(1, rj[j]));
		}
		sort(svi.begin(), svi.end());
		ll pravo = svi.back().second;
		REP(j, br_hash) rj[j] = pravo;
	}
	cout << rj[0] << endl;
	return 0;
}