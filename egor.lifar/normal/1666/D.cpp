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





int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	while (n--) {
		string s, t;
		cin >> s >> t;
		map<char, int> cnt;
		for (auto x: t) {
			cnt[x]++;
		}
		reverse(all(s));
		string d;
		for (auto x: s) {
			if (cnt[x]) {
				cnt[x]--;
				d += x;
			}
		}
		reverse(all(d));
		if (d ==t ){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}