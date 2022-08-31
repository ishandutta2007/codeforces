#include <iostream>
#include <vector>
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
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

const int maxn = 200000;
int a[maxn];
i64 b[maxn], t[maxn];

struct TNode {
    TNode *left, *right;
    i64 key;
    int L, R;

    TNode(int L = 0, int R = 0, i64 key = 0);

    void update() {
        key = max(left->key, right->key);
    }
};

TNode *null;

TNode::TNode(int L, int R, i64 key)
    : left(null)
    , right(null)
    , key(key)
    , L(L)
    , R(R)
{
}

//TNode tree[2][1000000];
//TNode *seg[2];
//int s[2];

i64 ans[2][1000000];

/*TNode *build(int i, int L, int R, i64 def) {
    TNode *node = &tree[i][s[i]++];
    *node = TNode(L, R, def);
    if (R - L > 1) {
        int M = (L + R) / 2;
        node->left = build(i, L, M, def);
        node->right = build(i, M, R, def);
    }
    return node;
}

void sset(TNode *root, int pos, i64 x) {
    if (pos >= root->R || pos < root->L) {
        return;
    }
    if (root->R - root->L == 1) {
        root->key = x;
        return;
    }
    sset(root->left, pos, x);
    sset(root->right, pos, x);
    root->update();
}

const i64 inf = 1e18;

i64 getMax(TNode *root, int l, int r) {
    if (l >= root->R || root->L >= r) {
        return -inf;
    }
    if (l <= root->L && root->R <= r) {
        return root->key;
    }
    return max(getMax(root->left, l, r), getMax(root->right, l, r));
} */

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    null = new TNode();
    null->key = -1e18;

    int N, M, D;
//    scanf("%d%d%d", &N, &M, &D);
    cin >> N >> M >> D;
    forn(i, M) {
        cin >> a[i] >> b[i] >> t[i];
        --a[i];
    }
//    seg[1] = build(1, 0, N, 0);
//    forn(j, N) {
//        sset(seg[1], j, b[0] - abs<i64>(a[0] - j));
//    }
    forn(j, N) {
        ans[1][j] = b[0] - abs(a[0] - j);
    }
    for (int i = 1; i < M; ++i) {
//        cerr << i << '\n';
 //       seg[i + 1] = build(0, N, -1e18);
        int ii = i & 1, iii = ii ^ 1;
//        s[iii] = 0;
//        seg[iii] = build(iii, 0, N, -inf);
//        cerr << "Built\n";
//        cerr << s[iii] << '\n';
//        multiset<i64> q;
        deque<int> q;
        int l = 0, r = 0;
        forn(j, N) {
//            sset(seg[iii], j, b[i] - abs<i64>(a[i] - j) + getMax(seg[ii], max(0LL, j - D * (t[i] - t[i - 1])), min((i64)N, j + D * (t[i] - t[i - 1]) + 1)));
            while (r < N && r - j <= D * (t[i] - t[i - 1])) {
//                q.insert(ans[ii][r]);
                while (!q.empty() && ans[ii][q.back()] <= ans[ii][r]) {
                    q.pop_back();
                }
                q.push_back(r);
                ++r;
            }
            while (l < N && j - l > D * (t[i] - t[i - 1])) {
                //q.erase(q.find(ans[ii][l]));
                if (!q.empty() && q.front() == l) {
                    q.pop_front();
                }
                ++l;
            }
//            cerr << l << ' ' << j << ' ' << r << '\n';
            ans[iii][j] = b[i] - abs(j - a[i]) + ans[ii][q.front()];
        }
//        cerr << "Done\n";
    }
//    cout << getMax(seg[M & 1], 0, N) << '\n';
    cout << *max_element(ans[M & 1], ans[M & 1] + N) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}