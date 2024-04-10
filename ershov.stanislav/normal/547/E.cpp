#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 4e5 + 100;
const int Q = 5e5 + 100;
const int M = 31;
const int MOD = 1e9 + 7;

char s[N];
int n, q, ls[N], rs[N], all;
int suff[N], p[N], cnt[N], classes[N], nclasses[N];
int lcp[N];
int sparse[20][N];
int mx_power[N];
vector<int> tree[N * 4];

void build (int v, int vl, int vr) {
    if (vl >= vr) {
        return;
    } else if (vr == vl + 1) {
        tree[v].pb(suff[vl]);
    } else {
        int mid = (vl + vr) / 2;
        build (v * 2 + 1, vl, mid);
        build (v * 2 + 2, mid, vr);
        tree[v].resize(tree[v * 2 + 1].size() + tree[v * 2 + 2].size());
        merge(all(tree[v * 2 + 1]), all(tree[v * 2 + 2]), tree[v].begin());
    }
}

int get_cnt(int v, int vl, int vr, int l, int r, int ll, int rr) {
    if (vl >= r || vr <= l) {
        return 0;
    } else if (vl >= l && vr <= r) {
        return (int) (lower_bound(all(tree[v]), rr) - lower_bound(all(tree[v]), ll));
    } else {
        int mid = (vl + vr) / 2;
        return get_cnt(v * 2 + 1, vl, mid, l, r, ll, rr) + get_cnt(v * 2 + 2, mid, vr, l, r, ll, rr);
    }
}

void build_sparse() {
    for (int i = 0; i < all - 1; i++) {
        sparse[0][i] = lcp[i];
    }
    for (int i = 1, j = 1; j < all - 1; j <<= 1, i++) {
        for (int k = 0; k < all - 1; k++) {
            sparse[i][k] = sparse[i - 1][k];
            if (k + j < all - 1) {
                sparse[i][k] = min(sparse[i][k], sparse[i - 1][k + j]);
            }
        }
    }
}

int get_min(int l, int r) {
    if (r <= l) {
        return INF;
    } else {
        int mx = mx_power[r - l];
        return min(sparse[mx][l], sparse[mx][r - (1 << mx)]);
    }
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &q);
    for (int i = 1, cur = 0; i <= n; i++) {
        scanf(" %s", s + cur);
        ls[i] = cur;
        cur += strlen(s + cur);
        rs[i] = cur++;
        s[rs[i]] = 'z' + 1;
    }
    all = rs[n];
    all++;

    for (int i = 0; i < 20; i++) {
        for (int j = (1 << i); j < (1 << (i + 1)) && j < N; j++) {
            mx_power[j] = i;
        }
    }

    for (int i = 0; i < all; i++) {
        classes[i] = s[i] - 'a';
        cnt[s[i] - 'a' + 1]++;
    }
    for (int i = 1; i < 27; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < all; i++) {
        suff[cnt[s[i] - 'a']++] = i;
    }
    for (int j = 1; j < all; j <<= 1) {
        for (int i = 0; i < all + 26; i++) {
            cnt[i] = 0;
        }
        for (int i = 0; i < all; i++) {
            cnt[classes[i] + 1]++;
        }
        for (int i = 1; i < all + 26; i++) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = 0; i < all; i++) {
            int a = (suff[i] - j + all) % all;
            p[cnt[classes[a]]++] = a;
        }
        nclasses[0] = 0;
        for (int i = 0; i < all; i++) {
            suff[i] = p[i];
            if (i > 0) {
                nclasses[p[i]] = nclasses[p[i - 1]];
                if (classes[p[i]] != classes[p[i - 1]] || classes[p[i]] == classes[p[i - 1]] &&
                        classes[(p[i] + j) % all] != classes[(p[i - 1] + j) % all]) {
                    nclasses[p[i]]++;
                }
            }
        }
        for (int i = 0; i < all; i++) {
            classes[i] = nclasses[i];
        }
    }
//    for (int i = 0; i < all; i++) {
//        cout << i << ' ' << s + suff[i] << endl;
//    }

    for (int i = 0; i < all; i++) {
        classes[suff[i]] = i;
    }

    for (int i = 0, k = 0; i < all; i++, k ? k-- : 0) {
        if (classes[i] == all - 1) {
            k = 0;
            continue;
        }
        int j = suff[classes[i] + 1];
        while (i + k < all && j + k < all && s[i + k] == s[j + k]) k++;
        lcp[classes[i]] = k;
    }

    build_sparse();
    build(0, 0, all);

    for (int i = 0; i < q; i++) {
        int L, R, k;
        scanf("%d%d%d", &L, &R, &k);

        int m = classes[ls[k]], lq = ls[L], rq = rs[R];
        int l = m, r = all - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (get_min(m, mid) >= rs[k] - ls[k]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        int b = l;
        l = 0, r = m + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (get_min(m - mid, m) >= rs[k] - ls[k]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        int a = m - l;

//        cout << a << ' ' << b << endl;

        printf("%d\n", get_cnt(0, 0, all, a, b + 1, lq, rq));
    }

    return 0;
}