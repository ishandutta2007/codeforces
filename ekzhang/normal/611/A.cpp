#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.emplace_back(x); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n'; err(++it, args...); }

int N;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> s;
	cin >> s;

	if (s == "week") {
		N = (N + 2) % 7;
		cout << (365 - N) / 7 + 1 << endl;
	}
	else if (s == "month") {
		if (N <= 29) {
			cout << 12 << endl;
		}
		else if (N <= 30) {
			cout << 11 << endl;
		}
		else if (N == 31) {
			cout << 7 << endl;
		}
	}

	cout.flush();
	return 0;
}