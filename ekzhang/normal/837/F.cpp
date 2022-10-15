#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
#define MAXN 200013
LL N, K;
LL A[MAXN];
int biggest = -1;

bool go(LL k) {
	// see if k+1 steps works
	LL combo = 1;
	LL X = 0;
	X += A[N - 1];
	for (int i = N - 2; i >= biggest; i--) {
		long double tester = combo;
		tester *= N + k - 1 - i;
		tester /= N - 1 - i;
		if (tester * 0.9 > K) {
			return true;
		}
		combo = llround(tester);
		
		if (A[i]) {
			tester = combo;
			tester *= A[i];
			tester += X;
			if (tester * 0.9 > K) return true;
			X += combo * A[i];
		}
	}
	if (X >= K) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] >= K) {
			cout << 0 << endl;
			return 0;
		}
		if (A[i] && biggest == -1) biggest = i;
	}

	LL lo = 0;
	LL hi = 1123456789123456789;

	while (lo != hi) {
		LL mid = (lo + hi) / 2;
		if (go(mid)) {
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}

	cout << lo + 1 << endl;
	return 0;
}