#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 500013
#define MAX 1000000000
int N, K;
int C[MAXN];

int main() { // I guess binary search always wins :)
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> C[i];
	}

	sort(C, C + N);

	int lo = 1;
	int hi = MAX;
	while (lo != hi) {
		error(lo, hi);
		int mid = (lo + hi + 1) / 2;
		long long amt = 0;
		for (int i = 0; i < N; i++) {
			if (mid > C[i]) {
				amt += mid - C[i];
			}
			else {
				break;
			}
		}
		if (amt > K) {
			hi = mid - 1;
		}
		else {
			lo = mid;
		}
	}

	int lv = lo;
	lo = 1;
	hi = MAX;
	while (lo != hi) {
		int mid = (lo + hi) / 2;
		long long amt = 0;
		for (int i = N - 1; i >= 0; i--) {
			if (mid < C[i]) {
				amt += C[i] - mid;
			}
			else break;
		}
		if (amt > K) {
			lo = mid + 1;
		}
		else {
			hi = mid;
		}
	}
	int hv = lo;
	error(lv, hv);

	int ans = max(hv - lv, 0);
	if (ans == 0) {
		long long su = 0;
		for (int i = 0; i < N; i++) {
			su += C[i];
		}
		if (su % N) {
			ans = 1;
		}
	}
	cout << ans << endl;
	return 0;
}