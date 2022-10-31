#include <bits/stdc++.h> 
 
using namespace std;
 
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
}

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 
 
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vi c(n);
	forn(i, n) {
		cin >> c[i];
	}
	unsigned long long ans = 0;
	for(int i = 0; i < n; i += 2) {
		ll curB = 0;
		ll minS = 1;
		ll canS = c[i];
		for(int j = i + 1; j < n; j++) {
			ll canT = c[j];
			if ((j % 2) == 0) {
				curB += canT;
				continue;
			}
			ll minT = max(curB + minS, 1ll);
			ll opsT = max(0ll, canT - minT + 1);
			ll opsS = max(0ll, canS - minS + 1);
		//	cerr << i << " " << j << " " << min(opsS, opsT) << '\n';
			ans += min(opsS, opsT);
			curB -= canT;
			minS = max(minS, -curB);
		}
	}
	cout << ans << '\n';
	return 0;
}