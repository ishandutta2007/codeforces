//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 8000;
bool adj[N][N];
bool done[N], part[N];
int indeg[N], inpart[N][2];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		for(int j=0; j<n; j++) {
			if(isdigit(s[j/4])) {
				adj[i][j] = (s[j/4]-'0') >> (3 - j%4) & 1;
			} else {
				adj[i][j] = (s[j/4]-'A'+10) >> (3 - j%4) & 1;
			}
			indeg[j] += adj[i][j];
		}
	}

	ll ans = 0;

	queue<int> inzero;
	for(int i=0; i<n; i++) {
		if(indeg[i] == 0) {
			inzero.push(i);
		}
	}
	while(!inzero.empty()) {
		int u = inzero.front();
		inzero.pop();
		done[u] = true;
		for(int i=0; i<n; i++) {
			if(adj[u][i]) {
				ans += 1 + 614*n;
				if(--indeg[i] == 0) {
					inzero.push(i);
				}
			}
		}
	}

	vector<int> valid;
	for(int i=0; i<n; i++) {
		if(!done[i]) {
			valid.push_back(i);
		}
	}

	int top = -1;
	for(int i : valid) {
		if(top == -1 || indeg[i] > indeg[top]) {
			top = i;
		}
	}
	if(top == -1) {
		cout << ans << nl;
		return 0;
	}

	for(int i : valid) {
		if(i == top || adj[i][top]) {
			part[i] = true;
		}
	}

	for(int i : valid) {
		for(int j : valid) {
			inpart[i][part[j]] += adj[j][i];
		}
	}

	vector<pair<int,int>> ispart, nopart;
	for(int i : valid) {
		if(part[i]) {
			ispart.push_back(make_pair(inpart[i][1], i));
		} else {
			nopart.push_back(make_pair(inpart[i][0], i));
		}
	}
	sort(ispart.begin(), ispart.end());
	sort(nopart.begin(), nopart.end());

	ans += (int)ispart.size() * (int)nopart.size() * 3;

	for(int i=0; i<ispart.size(); i++) {
		for(int j=0; j<ispart.size(); j++) {
			if(i == j) continue;
			int ii = ispart[i].second;
			int jj = ispart[j].second;
			if(i < j) {
				ans += 1;
			} else {
				ans += (inpart[ii][0] == inpart[jj][0] ? 3 : 2);
			}
		}
	}

	for(int i=0; i<nopart.size(); i++) {
		for(int j=0; j<nopart.size(); j++) {
			if(i == j) continue;
			int ii = nopart[i].second;
			int jj = nopart[j].second;
			if(i < j) {
				ans += 1;
			} else {
				ans += (inpart[ii][1] == inpart[jj][1] ? 3 : 2);
			}
		}
	}

	cout << ans << nl;

	return 0;
}