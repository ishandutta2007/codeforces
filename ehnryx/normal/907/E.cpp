#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

///* advent of code
typedef istringstream iss;
#define pb push_back
#define ins insert
#define multiset mset
#define getl(A) getline(cin, A)
//*/

const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;

vector<unordered_set<int>> init;
int n, m;

vector<int> solve(const vector<int>& perm) {
	int left = n*(n-1)/2 - m;
	vector<int> temp;
	vector<unordered_set<int>> cur = init;
	for (int i = 0; i < n; i++) {
		if (left == 0) break;
		int prev = left;
		for (int j : cur[perm[i]]) {
			for (int k : cur[perm[i]]) {
				if (k == j) continue;
				if (cur[j].count(k)) continue;
				cur[j].insert(k);
				cur[k].insert(j);
				left--;
			}
		}
		if (prev > left) {
			temp.push_back(perm[i]);
		}
	}
	return temp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	init.resize(n);

	int a,b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		init[a-1].insert(b-1);
		init[b-1].insert(a-1);
	}

	vector<int> perm;
	for (int i = 0; i < n; i++) {
		perm.push_back(i);
	}

	srand(clock() + time(nullptr));
	vector<int> ans;
	int best = INF;
	//int iters = 0;
	while (clock() < 0.95*CLOCKS_PER_SEC) {
		//iters++;
		random_shuffle(perm.begin(), perm.end());
		vector<int> temp = solve(perm);
		if (temp.size() < best) {
			ans = temp;
			best = temp.size();
		}
	}
	//cerr << "iterations: " << iters << nl;

	cout << ans.size() << nl;
	for (int it : ans) 
		cout << it+1 << " ";
	cout << nl;

	return 0;
}
////