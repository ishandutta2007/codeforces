#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

int N, K;
unordered_map<int, int> p;

inline long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	long long lcm = 1;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		lcm = lcm * x / gcd(lcm, x);
		lcm = gcd(lcm, K);
	}

	cout << (lcm % K == 0 ? "Yes" : "No") << endl;
	return 0;
}