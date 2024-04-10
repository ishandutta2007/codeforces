#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int Ps[2] = {(int) 1e9 + 7, (int) 1e9 + 9};

int power(int a, int p, int mod) {
    int ans = 1;
    while (p) {
        if (p & 1) {
            ans = (ll) ans * a % mod;
        }
        a = (ll) a * a % mod;
        p >>= 1;
    }
    return ans;
}

struct Hash{
    const static int n = 2;
    int a[2];
    Hash(int x = 0) {
        for (int i = 0; i < 2; i++) {
            a[i] = x % Ps[i];
        }
    }
    Hash operator+(const Hash & b) const {
        Hash res;
        for (int i = 0; i < n; i++) {
            res.a[i] = a[i] + b.a[i];
            if (res.a[i] >= Ps[i]) {
                res.a[i] -= Ps[i];
            }
        }
        return res;
    }
    Hash operator-(const Hash & b) const {
        Hash res;
        for (int i = 0; i < n; i++) {
            res.a[i] = a[i] - b.a[i];
            if (res.a[i] < 0) {
                res.a[i] += Ps[i];
            }
        }
        return res;
    }
    Hash operator*(const Hash & b) const {
        Hash res;
        for (int i = 0; i < n; i++) {
            res.a[i] = (ll) a[i] * b.a[i] % Ps[i];
        }
        return res;
    }
    bool operator<(const Hash & b) const {
        for (int i = 0; i < n; i++) {
            if (a[i] != b.a[i]) {
                return a[i] < b.a[i];
            }
        }
        return false;
    }
    bool operator==(const Hash & b) const {
        for (int i = 0; i < n; i++) {
            if (a[i] != b.a[i]) {
                return false;
            }
        }
        return true;
    }
};

Hash q;

const int maxn = 3e5 + 100;
int n;
int c[maxn];
int cnt[maxn];
char s[maxn];
vector<int> tree[maxn];
Hash qs[2000000];

inline Hash getpow(int p) {
    return qs[p + 1000000];
}

void join(pair<set<Hash>, pair<int, Hash>> & a, pair<set<Hash>, pair<int, Hash>> & b) {
    if (sz(a.first) < sz(b.first)) {
        swap(a, b);
    }
    Hash toadd = (b.second.second - a.second.second) * getpow(-a.second.first);
    Hash tomult = getpow(b.second.first - a.second.first);
    for (auto i : b.first) {
        a.first.insert(i * tomult + toadd);
    }
}

void dfs(int v, int par, pair<set<Hash>, pair<int, Hash>> & ans) {
    for (int i = 0; i < sz(tree[v]); i++) {
        if (tree[v][i] == par) {
            continue;
        }
        pair<set<Hash>, pair<int, Hash>> cur;
        cur.second.first = 0;
        cur.second.second = 0;
        dfs(tree[v][i], v, cur);
        join(ans, cur);
    }
    ans.second.first++;
    ans.second.second = ans.second.second * q;
    ans.second.second = ans.second.second + Hash(s[v]);
    pair<set<Hash>, pair<int, Hash> > toadd;
    toadd.first.insert(Hash(s[v]));
    toadd.second.first = 0;
    toadd.second.second = 0;
    join(ans, toadd);
    cnt[v] = sz(ans.first);
}

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    q = 239017 + rand() % 1000;
    Hash invq;
    invq.a[0] = power(q.a[0], Ps[0] - 2, Ps[0]);
    invq.a[1] = power(q.a[1], Ps[1] - 2, Ps[1]);
    qs[1000000] = 1;
    for (int i = (int) 1e6 + 1; i < 2e6; i++) {
        qs[i] = qs[i - 1] * q;
    }
    for (int i = (int) 1e6 - 1; i >= 0; i--) {
        qs[i] = qs[i + 1] * invq;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", c + i);
    }
    scanf(" %s", s);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    pair<set<Hash>, pair<int, Hash>> res;
        res.second.first = 0;
        res.second.second = 0;
    dfs(0, -1, res);
    pair<int, int> ans(-1, -1);
    for (int i = 0; i < n; i++) {
        if (c[i] + cnt[i] == ans.first) {
            ans.second++;
        }
        if (c[i] + cnt[i] > ans.first) {
            ans.first = c[i] + cnt[i];
            ans.second = 1;
        }
    }
    printf("%d\n%d\n", ans.first, ans.second);
    return 0;
}