#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e5;

int p[N];
int sz[N];

void make(int a) {
	p[a] = a;
	sz[a] = 1;
}

int get(int a) {
	if (a == p[a]) return a;
	return p[a] = get(p[a]);
}

void merge(int a, int b) {
	a = get(a);
	b = get(b);
	if (a != b) {
		if (sz[a] < sz[b]) swap(a, b);
		p[b] = a;
		sz[a] += sz[b];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(0); cin.tie(0);
	#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	vector <int> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		--p[i];
	}
	vector <int> good(n);
	int root = -1;
	for (int i = 0; i < n; ++i) {
		if (p[i] == i) {
			root = i;
			break;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) make(i);
	for (int i = 0; i < n; ++i) {
		if (i == root) continue;
		int a = i;
		int b = p[i];
		if (get(a) != get(b)) merge(a, b);
		else {
			++ans;
			if (root == -1) {
				root = i;
				p[i] = i;
			}
			else {
				p[i] = root;
				merge(i, root);
			}
		}
	}
	cout << ans << '\n';
	for (int i = 0; i < n; ++i) cout << p[i] + 1 << ' ';
	cout << '\n';
}