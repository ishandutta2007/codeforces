#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<iomanip>
#include<math.h>
#include<bitset>
#include<cassert>
#include<random>
#include<time.h>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

ll rando() {
	static random_device rd;
	static mt19937_64 mt(rd());
	return abs((ll)mt());
}

ll mana(vector<ll>& S) {
	int i = 0, j = 0;
	int n = S.size();
	vector<ll> R(n, 0);
	while (i < n) {
		while (i - j >= 0 && i + j < n && S[i - j] == S[i + j]) j++;
		R[i] = j;
		int k = 1;
		while (i - k >= 0 && i + k < n && k + R[i - k] < j) R[i + k] = R[i - k], k++;
		i += k; j -= k;
	}
	ll ret = 0;
	REP(i,n) {
		if(S[i] < 0 && S[i] != - INF) continue;
		if(S[i] == -INF) {
			if(i + (R[i] - 1) == n - 1 || i - (R[i] - 1) == 0) {
				ret += R[i] / 2;
			} else ret += R[i] / 2;
		}
		else {
			if(i + (R[i] - 1) == n - 1 || i - (R[i] - 1) == 0) {
				ret += R[i] / 2 + 1;
			} else ret += R[i] / 2;
		}
	}
	return ret;
}

/* --------------------------------------- */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<vector<char>> mat(n, vector<char>(m));
	REP(i,n) REP(j,m) cin >> mat[i][j];
	vector<vector<bitset<26>>> bit(n, vector<bitset<26>>(m + 1, bitset<26>(0)));
	REP(i,n) {
		bitset<26> tmp(0);
		REP(j,m) {
			if(tmp[mat[i][j] - 'a'] == 1) tmp[mat[i][j] - 'a'] = 0;
			else tmp[mat[i][j] - 'a'] = 1;
			bit[i][j + 1] = tmp;
		}
	}
	vector<ll> table(26);
	REP(i,26) table[i] = rando() % INF * 1000000LL;
	vector<vector<ll>> hash(n, vector<ll>(m + 1, 0));
	REP(i,n) REP(j,m) {
		hash[i][j + 1] = hash[i][j] + table[mat[i][j] - 'a'];
	}
	ll ans = 0;
	REP(i,m) FOR(j,i,m) {
		vector<ll> p(2 * n - 1, -INF);
		ll buf = 1;
		REP(k,n) {
			bitset<26> tmp = bit[k][i] ^ bit[k][j + 1];
			if(tmp.count() != ((j - i + 1) % 2)) {
				p[2 * k] = -buf;
				buf++;
			}
			else p[2 * k] = hash[k][j + 1] - hash[k][i];
		}
		ans += mana(p);
	}
	cout << ans << endl;
	return 0;
}
/* --------------------------------------- */