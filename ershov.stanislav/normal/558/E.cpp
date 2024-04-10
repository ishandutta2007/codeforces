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

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-10;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 1e5 + 100;

struct segm {
    vector<int> sum, change, changed;

    segm(int n = 0) {
        sum.resize(n * 4);
        change.resize(n * 4);
        changed.resize(n * 4);
    }

    void push(int v, int vl, int vr) {
        if (changed[v]) {
            changed[v * 2 + 1] = 1;
            changed[v * 2 + 2] = 1;
            change[v * 2 + 1] = change[v * 2 + 2] = change[v];
            int mid = (vl + vr) / 2;
            sum[v * 2 + 1] = change[v] * (mid - vl);
            sum[v * 2 + 2] = change[v] * (vr - mid);
            changed[v] = 0;
        }
    }

    void upd(int v, int vl, int vr, int l, int r, int x) {
        if (vl >= r || vr <= l) {
            return;
        }
        if (vl >= l && vr <= r) {
            change[v] = x;
            changed[v] = 1;
            sum[v] = (vr - vl) * x;
        } else {
            push(v, vl, vr);
            int mid = (vl + vr) / 2;
            upd(v * 2 + 1, vl, mid, l, r, x);
            upd(v * 2 + 2, mid, vr, l, r, x);
            sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
        }
    }

    int get(int v, int vl, int vr, int l, int r) {
        if (vl >= r || vr <= l) {
            return 0;
        }
        if (vl >= l && vr <= r) {
            return sum[v];
        } else {
            if (changed[v]) {
                return change[v] * (min(r, vr) - max(l, vl));
            }
            int mid = (vl + vr) / 2;
            return get(v * 2 + 1, vl, mid, l, r) + get(v * 2 + 2, mid, vr, l, r);
        }
    }

    void print(int v, int vl, int vr, vector<int> & vec) {
        if (changed[v]) {
            for (int i = vl; i < vr; i++) {
                vec.pb(change[v]);
            }
        } else {
            if (vr == vl + 1) {
                vec.pb(0);
            } else {
                int mid = (vl + vr) / 2;
                print(v + v + 1, vl, mid, vec);
                print(v + v + 2, mid, vr, vec);
            }
        }
    }
};

vector<segm> segms;
vector<int> ans[26];
int n, q;
char s[N];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &q);
    for (int i = 0; i < 26; i++) {
        segms.pb(segm(n));
    }
    scanf(" %s", s);
    for (int i = 0; i < n; i++) {
        segms[s[i] - 'a'].upd(0, 0, n, i, i + 1, 1);
    }

    for (int num = 0; num < q; num++) {
        int i, j, k;
        scanf("%d%d%d", &i, &j, &k);
        i--, j--;
        vector<int> cnt(26);
        for (int r = 0; r < 26; r++) {
            cnt[r] = segms[r].get(0, 0, n, i, j + 1);
//            cout << cnt[r] << ' ';
        }
//        cout << endl;
        if (k == 1) {
            for (int w = i, r = 0; r < 26; r++) {
                if (cnt[r]) {
                    segms[r].upd(0, 0, n, i, j + 1, 0);
                    segms[r].upd(0, 0, n, w, w + cnt[r], 1);
                    w += cnt[r];
                }
            }
        } else {
            for (int w = i, r = 25; r >= 0; r--) {
                if (cnt[r]) {
                    segms[r].upd(0, 0, n, i, j + 1, 0);
                    segms[r].upd(0, 0, n, w, w + cnt[r], 1);
                    w += cnt[r];
                }
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        segms[i].print(0, 0, n, ans[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if (ans[j][i]) {
                printf("%c", j + 'a');
            }
        }
    }
    printf("\n");
    return 0;
}