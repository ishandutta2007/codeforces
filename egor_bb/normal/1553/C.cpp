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


int compute(string s) {
	int score[2] = {0, 0}, left[2] = {5, 5};
	forn(i, 10) {
		if (s[i] == '1') {
			score[i % 2]++;
		}
		left[i % 2]--;
		if (score[0] + left[0] < score[1] || score[1] + left[1] < score[0]) {
			return i + 1;
		}
	}
	return 10;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int q;
	cin >> q;
	while(q--) {
		string s;
		cin >> s;
		string t;
		int ans = 10;
		forn(i, 2) {
			t = s;
			forn(j, 10) {
				if (j % 2 == i) {
					if (t[j] == '?') t[j] = '1';
				} else {
					if (t[j] == '?') t[j] = '0';
				}
			}
			ans = min(ans, compute(t));
		}
		cout << ans << '\n';
	}
	return 0;
}