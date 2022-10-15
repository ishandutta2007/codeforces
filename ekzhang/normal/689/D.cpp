#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
typedef pair<int, int> pii;

#define MAXN 200013
#define INF 1000000013
#define MAXLG 20
int N;
int A[MAXN], B[MAXN];
LL ans = 0;

int fa[MAXN], fb[MAXN]; // max, min

void ini() {
	for (int i = 0; i <= N; i++) {
		fa[i] = -INF;
	}
	for (int i = 0; i <= N; i++) {
		fb[i] = INF;
	}
}

int querya(int e) {
	int ans = -INF;
	for (int i = e + 1; i; i -= i & -i) {
		ans = max(ans, fa[i]);
	}
	return ans;
}

void updatea(int i, int x) {
	for (i++; i <= N; i += i & -i) {
		fa[i] = max(fa[i], x);
	}
}

int queryb(int e) {
	int ans = INF;
	for (int i = e + 1; i; i -= i & -i) {
		ans = min(ans, fb[i]);
	}
	return ans;
}

void updateb(int i, int x) {
	for (i++; i <= N; i += i & -i) {
		fb[i] = min(fb[i], x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	ini();

	for (int l = N - 1; l >= 0; l--) {
		updatea(l, A[l]);
		updateb(l, B[l]);

		int lo = l - 1;
		int hi = l - 1;
		for (int lg = MAXLG - 1; lg >= 0; lg--) {
			int x = (1<<lg);
			if (lo + x < N && querya(lo + x) < queryb(lo + x)) {
				lo += x;
			}
			if (hi + x < N && querya(hi + x) <= queryb(hi + x)) {
				hi += x;
			}
		}

		ans += hi - lo;
	}

	cout << ans << endl;
	return 0;
}