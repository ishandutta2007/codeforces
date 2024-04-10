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

const int nax = 1000 * 1000 + 10, mod = 1e9 + 7;
int t,n,p;
int k[nax];
vector<pi> cnt;
int mx, pot;
int add[nax];

int fast_pow(int a,int b) {
	int w = 1;
	while(b > 0) {
		if(b&1) w = ((ll)w  * a)%mod;
		a = ((ll)a * a) %mod;
		b/=2;
	}
	return w;
}

int main() {_
	cin >> t;
	while(t--) {
		cin >> n >> p;
		cnt.clear();
		for(int i = 1; i <= n; ++i) {
			cin >> k[i];
			add[i] = 0;
		}
		add[0] = 0;
		sort(k+1, k + n + 1);
		if(p == 1) {
			cout << n%2 << "\n";
			continue;
		}
		mx = 0, pot = 1;
		while(pot * p <= n) {
			pot *= p;
			mx ++;
		}
		int ile = 1;
		for(int i = 2; i <= n; ++i) {
			if(k[i] != k[i-1]) {
				cnt.PB({k[i-1], ile});
				ile = 1;
			} else {
				ile++;
			}
		}
		cnt.PB({k[n], ile});
		for(int i = 0; i < (int)cnt.size(); ++i) {
			add[i] = cnt[i].ND;
		}
		int bor = -1;
		for(int i = (int)cnt.size() - 1; i >= 0; --i) {
			if(cnt[i].ND % 2 == 0) continue;
			ll need = 1;
			int j = i - 1;
			while(j >= 0 && need > 0) {
				bool ok = 1;
				for(int ii = cnt[j+1].ST; ii > cnt[j].ST; --ii) {
					need *= p;
					if(need > n) {
						ok = 0;
						break;
					}
				}
				if(!ok) break;
				if(cnt[j].ND >= need) {
					cnt[j].ND -= need;
					add[j] = cnt[j].ND;
					need = 0;
				} else {
					need = need - cnt[j].ND;
					cnt[j].ND = 0;
				}
				j--;
			}
			if(need > 0) {
				bor = cnt[i].ST;
				break;
			}
		}
		if(bor == -1) {
			cout << "0\n";
			continue;
		}
		int s1 = fast_pow(p,bor), s2 = 0;
		for(int i = 0; i < (int)cnt.size(); ++i) {
			if(cnt[i].ST == bor) break;
			int w = ((ll)fast_pow(p, cnt[i].ST) * add[i]) % mod;
			s2 = (s2 + w) %mod;
		}
		s1 = (s1 - s2) %mod;
		if(s1 < 0) s1 += mod;
		cout << s1 << "\n";
				
	}
	
}