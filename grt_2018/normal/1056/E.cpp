#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 1'000'000 + 10;

string s, t;
int cnt[2];

const int p = 31, mod = 1e9 + 7;
int hsh[nax];
int pp[nax];

int get_hsh(int a, int b) {
	return (hsh[b] - (((ll)hsh[a - 1] * pp[b - a + 1])%mod) + mod) % mod;
}

int p2 = 33, mod2 = 1e9 + 33;
int hsh2[nax];
int pot2xd[nax];

int get_hsh2(int a, int b) {
	return (hsh2[b] - (((ll)hsh2[a - 1] * pot2xd[b - a + 1])%mod2) + mod2) % mod2;
}

int main() {_
	cin >> s >> t;
	hsh[0] = 0;
	pp[0] = 1;
	for(int i = 1; i <= (int)t.size(); ++i) {
		hsh[i] = ((ll)hsh[i - 1] * p + (t[i - 1] - 'a'+1)) % mod;
		pp[i] = ((ll)pp[i - 1] * p) % mod;
	}
	hsh2[0] = 0;
	pot2xd[0] = 1;
	for(int i = 1; i <= (int)t.size(); ++i) {
		hsh2[i] = ((ll)hsh2[i - 1] * p2 + (t[i - 1] - 'a'+1)) % mod2;
		pot2xd[i] = ((ll)pot2xd[i - 1] * p2) % mod2;
	}
	for(auto x : s) {
		cnt[x - '0']++;
	}
	int ans = 0;
	for(int l = 1; l < (int)t.size(); ++l) {
		ll rest = (ll)t.size() - (ll)l * cnt[0];
		if(rest <= 0 || rest % cnt[1] != 0) {
			continue;
		}
		int l2 = l;
		int r = (rest / cnt[1]);
		bool ok = 1;
		//~ cout << " " << l2 << " " << r << "\n";
		pi ww[2];
		for(int c : {0, 1}) {
			int cur = 1;
			pi act = {-1, -1};
			for(auto x : s) {
				if(x - '0' == c) {
					int hx = get_hsh(cur, cur + l2 - 1);
					int hy = get_hsh2(cur, cur + l2 - 1);
					//~ int hy = -1;
					if(act.ST < 0) {
						act = {hx, hy};
					} else {
						if(act != make_pair(hx, hy)) {
							ok = 0;
						}
					}
					cur += l2;
				} else {
					cur += r;
				}
			}
			//~ cout << act.ST << " " << act.ND << "\n";
			ww[c] = act;
			swap(l2, r);
		}
		if(ww[0] == ww[1]) ok = 0;
		ans += ok;
	}
	cout << ans;
			
				
}