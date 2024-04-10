#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.emplace_back(x); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
long long A, B;

int highestbit(LL N) {
	int ans = 0;
	while (N != 0) {
		N /= 2;
		ans++;
	}
	return ans;
}

int solve(LL N) {
	int ans = 0;
	for (int i = 0;; i++) {
		int curr = 0;
		LL num = ((1LL<<(i+2)) - 1) - (1LL<<i);
		for (int j = i + 2;; j++) {
			if (num <= N) {
				curr++;
			}
			else {
				break;
			}
			num += (1LL << j);
		}
		if (curr == 0) {
			break;
		}
		ans += curr;
		// cout << i << ' ' << ans << endl;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> A >> B;

	cout << solve(B) - solve(A - 1) << endl;
	return 0;
}