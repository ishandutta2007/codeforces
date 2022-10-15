#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
#define MAXN 300013
int N, P;
int X[MAXN], Y[MAXN];
map<pair<int, int>, int> m;
int h[MAXN];
int res[MAXN];
LL ans = 0;

int fenwick[MAXN];
int query(int i) {
	int ret = 0;
	// error(i);
	for (i++; i; i -= i & -i) {
		ret += fenwick[i];
	}
	return ret;
}

void update(int i) {
	for (i++; i < MAXN; i += i & -i) {
		fenwick[i]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> P;
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];
		X[i]--; Y[i]--;
		if (X[i] > Y[i]) swap(X[i], Y[i]);
		h[X[i]]++;
		h[Y[i]]++;
		m[pair<int, int> {X[i], Y[i]}]++;
	}

	// sweepline
	for (int i = N - 1; i >= 0; i--) {
		res[i] = (N - 1) - i;
		if (P > h[i])
			res[i] -= query(P - h[i] - 1);
		update(h[i]);

		ans += res[i];
	}

	for (auto p : m) {
		int x = p.first.first;
		int y = p.first.second;
		int amt = p.second;
		if (h[x] + h[y] >= P && h[x] + h[y] - amt < P) {
			ans--;
		}
	}

	cout << ans << endl;
	return 0;
}