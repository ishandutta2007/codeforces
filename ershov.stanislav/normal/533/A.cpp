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

const int INF = 1e9 + 100;
const ll lINF = 4e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 5e5 + 100;

int n, k, h[N], s[N], mn = INF, mxh[N], should = INF;

vector<int> graph[N];
vector<int> can, need;

void dfs1(int v, int par = -1, int mx = INF) {
    mxh[v] = mx;
    mx = min(mx, h[v]);
    can.pb(mx);
    for (auto j : graph[v]) {
        if (j != par) dfs1(j, v, mx);
    }
}

void dfs2(int v, int par, map<int, int> & ans) {
    map<int, int> ans2;
    for (auto j : graph[v]) {
        if (j != par) {
            dfs2(j, v, ans2);
            if (ans.size() < ans2.size()) {
                swap(ans, ans2);
            }
            for (auto k : ans2) {
                ans[k.fs] += k.sc;
            }
            ans2.clear();
        }
    }
//    cout << "v = " << v << ": ";
//    for (auto i : ans) {
//        for (int j = 0; j < i.sc; j++) {
//            cout << i.fs << ' ';
//        }
//    }
//    cout << endl;
    if (mxh[v] >= need[0] && h[v] <= should) {
        bool flag = true;
        ans[need[0]]++;
        map<int, int>::reverse_iterator j = ans.rbegin();
        for (int i = 0; i < (int) need.size(); i++) {
            while (j != ans.rend() && j->sc == 0) {
                j++;
            }
            if (j == ans.rend() || j->fs < need[i]) {
                flag = false;
            } else {
                j->sc--;
            }
        }
        if (flag) {
            mn = min(mn, need[0] - h[v]);
        }
        ans.clear();
    } else {
        while (ans.size() > 0 && ans.rbegin()->fs > h[v]) {
            int p = ans.rbegin()->sc;
            ans.erase(ans.rbegin()->fs);
            ans[h[v]] += p;
        }
        ans[h[v]]++;
    }
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &s[i]);
    }

    dfs1(1);

    sort(s, s + k);
    reverse(s, s + k);
    sort(all(can));
    reverse(all(can));

    for (int i = 0, j = 0, delta = 0; i < k; i++) {
        delta--;
        while (j < (int) can.size() && can[j] >= s[i]) {
            j++;
            delta++;
        }
        if (j < i + 1) {
            should = min(should, s[i] - 1);
        }
        if (delta < 0) {
            need.pb(s[i]);
            delta++;
        }
    }

//    for (auto i : need) {
//        cout << i << ' ';
//    }
//    cout << endl;

    if (need.size() == 0) {
        cout << 0 << endl;
    } else {
        map<int, int> res;
        dfs2(1, -1, res);
        if (mn == INF) {
            cout << "-1" << endl;
        } else {
            cout << mn << endl;
        }
    }

    return 0;
}