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

const int N = 4e6 + 10;

int totalSum = 0, totalAdd = 0;
int ans[N], toAdd[N];

int add(int a, int b, int mod) {
	a += b;
	return a >= mod ? a - mod : a;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	ans[1] = 1;
	forab(i, 1, n + 1) {
		totalAdd = add(totalAdd, toAdd[i], m);
		ans[i] = add(ans[i], totalAdd, m);
		ans[i] = add(ans[i], totalSum, m);
		totalSum = add(totalSum, ans[i], m);
		for(int j = i * 2, k = 2; j <= n; j += i, k++) {
			toAdd[j] = add(toAdd[j], ans[i], m);
			int posNext = j + k;
			if (posNext <= n) {
				toAdd[posNext] = add(toAdd[posNext], m - ans[i], m);
			}
		} 
	}
	cout << ans[n] << '\n';
	return 0;
}