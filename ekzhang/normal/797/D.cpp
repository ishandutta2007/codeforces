#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define INF 1123456789
#define MAXN 100013
int N;
int V[MAXN];
int L[MAXN], R[MAXN];
set<int> willfind;
bool hasparent[MAXN];

void dfs(int n, int lo, int hi) {
	if (n == -1) return;
	if (V[n] >= lo && V[n] <= hi) {
		willfind.insert(V[n]);
	}
	dfs(L[n], lo, min(hi, V[n] - 1));
	dfs(R[n], max(lo, V[n] + 1), hi);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> V[i] >> L[i] >> R[i];
		if (~L[i]) L[i]--;
		if (~R[i]) R[i]--;
		hasparent[L[i]] = true;
		hasparent[R[i]] = true;
	}

	int root;
	for (int i = 0; i < N; i++) {
		if (!hasparent[i]) {
			root = i;
			break;
		}
	}

	dfs(root, 0, INF);

	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (!willfind.count(V[i])) {
			ans++;
		}
	}

	cout << ans << endl;
	return 0;
}