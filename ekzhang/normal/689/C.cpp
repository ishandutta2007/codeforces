#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
#define MAXM 1000000000000013LL

LL M;

LL amt(LL N) {
	// find M for any N
	LL ans = 0;
	for (LL k = 2; k * k * k <= N; k++) {
		ans += 	N / (k * k * k);
		if (ans > MAXM) {
			return ans; // lol too big anyway; don't want overflow
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> M;
	LL lo = 8;
	LL hi = 8 * MAXM; // too big but w/e
	while (lo < hi) {
		LL mid = (lo + hi) / 2;
		if (amt(mid) < M) {
			lo = mid + 1;
		}
		else {
			hi = mid;
		}
	}
 	
	if (amt(lo) == M) {
		cout << lo << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}