#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define all(c) (c).begin(), (c).end()
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int N = 1e6 + 100;

int n;
int odd[N], isLeaf[N];
vector<int> leaves;
vector<int> order;

void dfs(int v, int cur, int maxSz) {
	odd[v] = cur;
	maxSz--;
	if (maxSz == 0) {
		isLeaf[v] = 1;
		order.pb(v);
	} else {
		dfs(2 * v, 1 - cur, maxSz / 2);
		order.pb(v);
		dfs(2 * v + 1, cur, maxSz / 2);
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int tSize = 1;
    while(tSize * 2 - 1 <= n) {
    	tSize *= 2;
    }
    tSize--;
    dfs(1, 0, tSize);
    int gotToFix = n - tSize;
    forn(i, sz(order) - 1) {
    	int v = order[i], u = order[i + 1];
    	if (odd[v] == odd[u]) {
    //		cout << v << " " << u << '\n';
    		if (!isLeaf[v] && !isLeaf[u]) {
    			cout << 0 << '\n';
    			return 0;
    		}
    		gotToFix--;
    	}
    }
    if (gotToFix == 0 || gotToFix == 1) {
    	cout << 1 << '\n';
    } else {
    	cout << 0 << '\n';
    }
    return 0;
}