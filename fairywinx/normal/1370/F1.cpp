#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <assert.h>
#include <deque>

using namespace std;

const int N = 1e3 + 228;

vector<int> G[N];
int d[N];
int mxd = 0;

void dfs(int v, int p, int h) {
    d[v] = h;
    mxd = max(mxd, h);
    for(auto i: G[v]) {
        if (i == p)
            continue;
        dfs(i, v, h + 1);
    }
}

void dfs_s(int v, int p, int now_h, vector<int> &q) {
    if (now_h == 0) {
        q.push_back(v + 1);
        return;
    }
    if (now_h < 0)
        return;

    for(auto i: G[v]) {
        if (i == p)
            continue;
        dfs_s(i, v, now_h - 1, q);
    }
}

void solve() {
	int n;
	cin >> n;
	mxd = 0;
	for(int i = 0; i < N; ++i)
	    G[i] = vector<int> ();
	for(int i = 0; i < n - 1; ++i) {
	    int a, b;
	    cin >> a >> b;
	    G[a - 1].push_back(b - 1);
	    G[b - 1].push_back(a - 1);
	}
	dfs(0, 0, 0);
	cout << "? " << n << ' ';
	for(int i = 1; i <= n; ++i)
	    cout << i << ' ';
	cout << endl;
	int D;
	cin >> D >> D;
	int l = 0, r = mxd + 1;
	while(r - 1 > l) {
	    vector<int> q;
        int m = (l + r) / 2;
//        cout << D << ' ' << l << ' ' << r << endl;
	    cout << "? ";
	    for(int i = 0; i < n; ++i) {
	        if (d[i] >= m)
	            q.push_back(i + 1);
	    }
//	    assert(q.size() != 0);
	    cout << q.size() << ' ';
	    for(auto i: q)
	        cout << i << ' ';
	    cout << endl;
	    int dist, tmp;
	    cin >> tmp >> dist;
	    if (dist == D)
	        l = m;
	    else
	        r = m;
	}
	cout << "? ";
	vector<int> q;
	for(int i = 0; i < n; ++i) {
	    if (l == d[i])
	        q.push_back(i + 1);
	}
    assert(q.size() != 0);
	cout << q.size() << ' ';
	for(auto i: q)
	    cout << i << ' ';
	cout << endl;
	int v, dist;
	cin >> v >> dist;
	cout << "? ";
	q.clear();
	dfs_s(v - 1, -1, dist, q);
    assert(q.size() != 0);
	cout << q.size() << ' ';
	for(auto i: q)
	    cout << i << ' ';
	cout << endl;
	int u;
	cin >> u >> dist;
	cout << "! " << v << ' ' << u << endl;
	string s;
	cin >> s;
	assert(s != "Incorrect");
}

int main() {
//#ifdef MEOW
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#else
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//#endif

    int t;
    cin >> t;
    while(t--)
        solve();
}