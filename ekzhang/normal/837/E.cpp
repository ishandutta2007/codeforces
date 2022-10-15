#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;

vector<LL> factors;

inline LL gcd(LL a, LL b) {
	return b == 0 ? a : gcd(b, a % b);
}

inline void pfactor(LL x) {
	factors.clear();
	if (x % 2 == 0) {
		factors.push_back(2);
		while (x % 2 == 0) x /= 2;
	}
	for (LL d = 3; d * d <= x; d += 2) {
		if (x % d == 0) {
			factors.push_back(d);
			while (x % d == 0) x /= d;
		}
	}
	if (x != 1) factors.push_back(x);
}

LL go(LL a, LL b) {
	if (b == 0) return 0;
	pfactor(a);
	LL highest = 0;
	for (LL d : factors) {
		highest = max(highest, d * (b / d));
	}
	LL g = gcd(a, highest);
	return b - highest + go(a / g, highest / g);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	LL A, B;
	cin >> A >> B;

	cout << go(A, B) << endl;
	return 0;
}