#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.emplace_back(x); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 200005
int pfx[MAXN][2];
string a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> a >> b;
	int N = a.size();
	for (int i = 0; i < N; i++) {
		pfx[i + 1][0] = pfx[i][0];
		pfx[i + 1][1] = pfx[i][1];
		pfx[i + 1][a[i] - '0']++;
	}

	int M = b.size();
	long long ans = 0;
	for (int i = 0; i < b.size(); i++) {
		int s = max(0, i - M + N);
		int e = min(N, i + 1);
		int w = 1 - (b[i] - '0');
		ans += pfx[e][w] - pfx[s][w];
	}

	cout << ans << endl;
	return 0;
}