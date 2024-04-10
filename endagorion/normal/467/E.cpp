#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)((n) - 1); i >= 0; --i)
#define fornn(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define debugv(a) forn(i, a.size()) cerr << a[i] << ' '; cerr << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

typedef long long i64;
typedef pair<i64, i64> pi64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

typedef long double ld;

int a[600000];
int nxt[600000];

struct TNode {
    int left, right;
    int L, R;
    int key;

    TNode(int L = 0, int R = 0)
        : left(-1)
        , right(-1)
        , L(L)
        , R(R)
        , key(0)
    {
    }
};

TNode tree[2000000];
int dp[600000];    
int prv[600000];
int tc = 0;

int buildTree(int L, int R) {
    int node = tc++;
    tree[node] = TNode(L, R);
    tree[node].key = -1;
    
    if (R - L == 1) {
        return node;
    }

    int M = (L + R) / 2;
    tree[node].left = buildTree(L, M);
    tree[node].right = buildTree(M, R);
    return node;
}

int getMax(int node, int L, int R) {
    if (tree[node].R <= L || R <= tree[node].L) return -1e9;
    if (L <= tree[node].L && tree[node].R <= R) return tree[node].key;
    return max(getMax(tree[node].left, L, R), getMax(tree[node].right, L, R));
}

void sset(int node, int i, int x) {
    if (i < tree[node].L || i >= tree[node].R) return;
    if (tree[node].R - tree[node].L == 1) {
        tree[node].key = max(tree[node].key, x);
        return;
    }
    int left = tree[node].left, right = tree[node].right;
    sset(left, i, x);
    sset(right, i, x);
    tree[node].key = max(tree[left].key, tree[right].key);
}

int main() {
    int N;
    scanf("%d", &N);
    forn(i, N) scanf("%d", &a[i]);
    map<int, int> occ;
    ford(i, N) {
        if (occ.count(a[i])) nxt[i] = occ[a[i]];
            else nxt[i] = -1;
        occ[a[i]] = i;
    }
    int root = buildTree(0, N);
    forn(i, N + 1) prv[i] = -1;
    forn(i, N) {
        int j = nxt[i];
        if (dp[i + 1] < dp[i]) {
            dp[i + 1] = dp[i];
            prv[i + 1] = -1;
        }

//        cerr << i << ' ' << j << '\n';
        if (j == -1) continue;
        int x = getMax(root, i + 1, nxt[i]);
        if (x >= 0) {
            if (dp[x] + 1 > dp[nxt[i] + 1]) {
                dp[nxt[i] + 1] = dp[x] + 1;
                prv[nxt[i] + 1] = x;
            }
        }                         
        sset(root, j, i);

        j = nxt[i];
        forn(k, 2) if (j != -1) j = nxt[j];
        if (j != -1) {
            if (dp[i] + 1 > dp[j + 1]) {
                dp[j + 1] = dp[i] + 1;
                prv[j + 1] = i;
            }
        }
    }
    int m = 0;
/*    forn(i, N + 1) cerr << dp[i] << ' ';
    cerr << '\n';
    forn(i, N + 1) cerr << prv[i] << ' ';
    cerr << '\n';*/

    forn(i, N + 1) if (dp[i] > dp[m]) m = i;
//    --m;
    printf("%d\n", 4 * dp[m]);
    vi ans;
    while (m >= 0) {
        if (prv[m] == -1) --m;
        else {
            forn(i, 2) {
                ans.pb(a[m - 1]);
                ans.pb(a[prv[m]]);
            }
            m = prv[m];
        }
    }
    reverse(all(ans));
    forn(i, ans.size()) {
        printf("%d ", ans[i]);
    }
    printf("\n");

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}