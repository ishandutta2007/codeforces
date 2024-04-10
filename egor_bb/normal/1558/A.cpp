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

set<int> s;

void solve(int a, int b, int k1, int k2) {
	int breakA = 0, gotA = 0, breakB = 0, gotB = 0;
	gotA = min(a, k1);
	gotB = min(b, k2);
	if (a > k1) breakA = a - k1; 
	if (b > k2) {
		breakB = b - k2;
		swap(a, b);
		swap(k1, k2);
		swap(breakA, breakB);
		swap(gotA, gotB);
	}
	s.insert(breakA + breakB);
	while(true) {
		breakA++;
		gotB--;
		gotA--;
		breakB++;
		if (gotA < 0 || gotB < 0) {
			break;
		}
		s.insert(breakA + breakB);
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		int n = a + b;
		s.clear();
		if (n % 2 == 0) {
			solve(a, b, n / 2, n / 2);
		} else {
			solve(a, b, n / 2, n / 2 + 1);
			solve(a, b, n / 2 + 1, n / 2);
		}
		cout << sz(s) << '\n';
		for(int x : s) {
			cout << x << " ";
		}
		cout << '\n';
	}
	return 0;
}