#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MOD 1000000007
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	// problem is to count the number of a.....b "inversions"

	cin >> s;
	long long ans = 0;
	long long t = 0;
	reverse(s.begin(), s.end());
	for (char c : s) {
		if (c == 'a') {
			ans += t;
			ans %= MOD;
			t *= 2;
			t %= MOD;
		}
		else {
			t++;
			t %= MOD;
		}
	}

	cout << ans << endl;
	return 0;
}