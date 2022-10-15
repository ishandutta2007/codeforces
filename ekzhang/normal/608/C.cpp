#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.emplace_back(x); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 100005

int N;
pair<int, int> ipt[MAXN];
int pos[MAXN];
int des[MAXN];
int desct[MAXN];
int d[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> ipt[i].first >> ipt[i].second;
	}
	sort(ipt, ipt + N);

	for (int i = 0; i < N; i++) {
		pos[i] = ipt[i].first;
		int B = ipt[i].second;
		des[i] = lower_bound(pos, pos + i, pos[i] - B) - pos;
		desct[i] = i - des[i];
	}

	d[0] = 0;
	int ans = 1<<30;
	for (int i = 1; i <= N; i++) {
		d[i] = desct[i - 1] + d[des[i-1]];
		ans = min(ans, d[i] + N - i);
		// error(i, d[i], des[i]);
	}



	cout << ans << endl;
	return 0;
}