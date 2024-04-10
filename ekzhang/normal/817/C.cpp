#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
LL N, S;

bool is_big(LL x) {
	string s = to_string(x);
	LL digsum = 0;
	for (char c : s) {
		digsum += c - '0';
	}
	return x - digsum >= S;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> S;
	LL lo = 1;
	LL hi = N + 1;
	while (lo != hi) {
		LL mid = (lo + hi) / 2;
		if (is_big(mid)) {
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}

	cout << N + 1 - lo << endl;
	return 0;
}