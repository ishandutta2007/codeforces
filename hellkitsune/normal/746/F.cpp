#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
#define sz(x) int(x.size())

const int INF = int(1e9);

int n, w, k;
int a[200005];
int t[200005];

struct Cmp {
    inline bool operator()(const int &lhs, const int &rhs) const {
        if (t[lhs] != t[rhs]) return t[lhs] > t[rhs];
        return lhs < rhs;
    }
};

struct Cmp2 {
    inline bool operator()(const int &lhs, const int &rhs) const {
        if (t[lhs] != t[rhs]) return t[lhs] < t[rhs];
        return lhs < rhs;
    }
};

set<int, Cmp> lo;
set<int, Cmp2> hi;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &w, &k);
    forn(i, n) {
        scanf("%d", a + i);
    }
    forn(i, n) {
        scanf("%d", t + i);
    }
    int cur = 0;
    int sumT = 0;
    int ans = 0;
    int j = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        int mx = (lo.empty() ? -INF : t[*lo.begin()]);
        int mn = (hi.empty() ? INF : t[*hi.begin()]);
        if (t[i] >= mx && t[i] <= mn) {
            if (sz(hi) < w) {
                hi.insert(i);
                sumT += (t[i] + 1) / 2;
            } else {
                lo.insert(i);
                sumT += t[i];
            }
        } else if (t[i] < mx) {
            lo.insert(i);
            sumT += t[i];
        } else {
            hi.insert(i);
            sumT += (t[i] + 1) / 2;
        }
        if (sz(hi) > w) {
            int val = *hi.begin();
            hi.erase(hi.begin());
            lo.insert(val);
            sumT -= (t[val] + 1) / 2;
            sumT += t[val];
        }

//        for (int x : lo) cerr << t[x] << ' ';
//        cerr << endl;
//        for (int x : hi) cerr << t[x] << ' ';
//        cerr << endl;
//        cerr << "---" << endl;

        cur += a[i];
        while (sumT > k) {
            auto it = lo.find(j);
            if (it == lo.end()) {
                hi.erase(j);
                sumT -= (t[j] + 1) / 2;
                if (!lo.empty()) {
                    int val = *lo.begin();
                    lo.erase(lo.begin());
                    hi.insert(val);
                    sumT -= t[val];
                    sumT += (t[val] + 1) / 2;
                }
            } else {
                lo.erase(it);
                sumT -= t[j];
            }
            cur -= a[j];
            --j;
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}