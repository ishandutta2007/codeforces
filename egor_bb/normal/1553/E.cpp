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


bool check(int x, vector<int> a, int m) {
	int n = sz(a);
	vector<int> used(n, 0);
	int res = 0;
	forn(pos, n) {
		if (used[pos]) continue;
		int truePos = (a[pos] + x) % n;
		used[pos] = 1;
		while(!used[truePos]) {
			used[truePos] = 1;
			res++;
			truePos = (a[truePos] + x) % n;
		}
	}
	return res <= m;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int q;
	cin >> q;
	while(q--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		map<int, int> vote;
		forn(i, n) {
			cin >> a[i];
			a[i]--;
			vote[(n + i - a[i]) % n]++;
		}
		vector<int> cands;
		for(auto &p : vote) {
			if (p.snd + m * 2 >= n) {
				cands.pb(p.fst);
			}
		}
		vector<int> ans;
		sort(all(cands));
		for(auto x : cands) {
			if (check(x, a, m)) {
				ans.pb(x);
			}
		}
		cout << sz(ans) << " ";
		for(auto x : ans) cout << x << " ";
		cout << '\n';
	}
	return 0;
}