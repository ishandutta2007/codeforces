#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
int N;
map<LL, LL> cubes; // all cubes under 10^18 => cbrt

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	for (LL x = 1; x <= 1e6 + 13; x++) {
		cubes[x * x * x] = x;
	}
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		LL a, b;
		cin >> a >> b;
		LL c = a * b;
		if (cubes.count(c)) {
			c = cubes[c];
			if (a % c == 0 && b % c == 0) {
				cout << "Yes" << '\n';
				continue;
			}
		}
		cout << "No" << '\n';
	}

	cout.flush();
	return 0;
}