#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
#define mp make_pair
#define f first
#define s second
#define tcT template<class T
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

#define each(a, x) for(auto& a: x)

const int MOD = 1e9+7;
const db PI = acos((db)-1);
mt19937 rng(0);

tcT> bool ckmin(T& a, const T& b){
	return b < a ? a = b, 1 : 0;
}
tcT> bool ckmax(T& a, const T& b){
	return a < b ? a = b, 1 : 0;
}


const int MAXN = 20228;


string s;
int divs[MAXN];
int good[MAXN]; //middle
int good1[MAXN];//upper middle
int good2[MAXN];//bottom middle
int good3[MAXN];//left middle
int good4[MAXN];//right middle
int good5[MAXN];//left top
int good6[MAXN];//right top
int good7[MAXN];//left bottom
int good8[MAXN];//right bottom
int sum[MAXN];


int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> s;
	for (int i = 2; i <= sz(s); i+= 2) {
		for (int j = i; j <= sz(s); j += i) {
			divs[j]++;
		}
	}
	for (int i = 2; i <= sz(s); i++) {
		sum[i] = sum[i - 2] + divs[i] - 2;
	}
	int ans = 0;
	for (int t = 0; t < 2; t++) {
		int cnt = 0;
		for (int i = t; i + 1 < sz(s); i += 2) {
			if (s[i] == 'R' && s[i + 1] == 'L') {
				cnt++;
			} else {
				cnt = 0;
			}
			ans -= sum[cnt * 2];
		}
	}
	for (int t = 0; t < 2; t++) {
		int cnt = 0;
		for (int i = t; i + 1 < sz(s); i += 2) {
			if (s[i] == 'D' && s[i + 1] == 'U') {
				cnt++;
			} else {
				cnt = 0;
			}
			ans += cnt;
		}
	}
	for (int m = 2; m <= sz(s) / 2; m++){
		for (int i = 0; i < sz(s); i++) {
			int cnt = 0;
			if (i && s[i - 1] == 'R') {
				cnt++;
			}
			if (i + 1 < sz(s) && s[i + 1] == 'L') {
				cnt++;
			}
			if (i >= m && s[i - m] == 'D') {
				cnt++;
			}
			if (i + m < sz(s) && s[i + m] == 'U') {
				cnt++;
			}
			good[i] = (cnt == 1);
			good1[i] = (cnt - (i >= m && s[i - m] == 'D') == 1);
			good2[i] = (cnt - (i + m < sz(s) && s[i + m] == 'U') == 1);
			if (i) {
				good[i] += good[i - 1];
				good1[i] += good1[i - 1];
				good2[i] += good2[i - 1];
			}
			good3[i] = (cnt - (i && s[i - 1] == 'R') == 1);
			good4[i] = (cnt - (i + 1 < sz(s) && s[i + 1] == 'L') == 1);
			good5[i] = (cnt - (i && s[i - 1] == 'R') - (i >= m && s[i - m] == 'D') == 1);
			good6[i] = (cnt - (i + 1 < sz(s) && s[i + 1] == 'L') - (i >= m && s[i - m] == 'D') == 1);
			good7[i] = (cnt - (i && s[i - 1] == 'R') - (i + m < sz(s) && s[i + m] == 'U') == 1);
			good8[i] = (cnt - (i + 1 < sz(s) && s[i + 1] == 'L') - (i + m < sz(s) && s[i + m] == 'U') == 1);
		}
		for (int rem = 0; rem < m; rem++) {
			int cnt = 0;
			for (int i = rem; i + m <= sz(s); i += m) {
				if (i >= m) {
					if (!(good[i - 2] - good[i - m] == m - 2 && good3[i - m] && good4[i - 1])) {
						cnt = 0;
					} 
					if (good1[i - 2] - good1[i - m] == m - 2 && good5[i - m] && good6[i - 1]) {
						cnt++;
					}
				}
				if (good2[i + m - 2] - good2[i] == m - 2 && good7[i] && good8[i + m - 1]) {
					ans += cnt;
				}
			}
		}
	}
	cout << ans << '\n';
}