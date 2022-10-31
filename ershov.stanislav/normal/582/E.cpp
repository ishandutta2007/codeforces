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

const int N = 550;
const int MOD = 1e9 + 7;

char s[N];
int n, val[16], known[16][4], istrue, isknown;

int mult(int a, int b) {
    return (int) ((a * 1ll * b) % MOD);
}

int add(int a, int b) {
    int ans = a + b;
    if (ans >= MOD) {
        ans -= MOD;
    }
    return ans;
}

vector<int> join(vector<int> a, vector<int> b) {
    vector<int> ans(1 << 16);
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < (1 << 16); j++) {
            if (j & (1 << i)) {
                a[j] = add(a[j], a[j ^ (1 << i)]);
                b[j] = add(b[j], b[j ^ (1 << i)]);
            }
        }
    }
    for (int i = 0; i < (1 << 16); i++) {
        ans[i] = mult(a[i], b[i]);
    }
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < (1 << 16); j++) {
            if (j & (1 << i)) {
                ans[j] = add(ans[j], MOD - ans[j ^ (1 << i)]);
            }
        }
    }
    return ans;
}

vector<int> solve(int l, int r) {
    vector<int> ans(1 << 16);
    if (r == l + 1) {
        vector<char> ispossible;
        if (s[l] == '?') {
            for (char c = 'A'; c <= 'D'; c++) {
                ispossible.pb(c);
            }
            for (char c = 'a'; c <= 'd'; c++) {
                ispossible.pb(c);
            }
        } else {
            ispossible.pb(s[l]);
        }
        for (auto c : ispossible) {
            int cur = 0;
            int i;
            if (c >= 'A' && c <= 'D') {
                i = c - 'A';
            } else {
                i = c - 'a';
            }
            for (int mask = 0; mask < 16; mask++) {
                if (((mask & (1 << i)) && c >= 'A' && c <= 'D') || (!(mask & (1 << i)) && c >= 'a' && c <= 'd')) {
                    cur += 1 << mask;
                }
            }
            ans[cur]++;
        }
    } else {
        int mid = l + 1;
        int balance = 1;
        while (balance) {
            if (s[mid] == '(') {
                balance++;
            } else if (s[mid] == ')') {
                balance--;
            }
            mid++;
        }
        vector<int> vl = solve(l + 1, mid - 1);
        vector<int> vr = solve(mid + 2, r - 1);
        if (s[mid] == '|' || s[mid] == '?') {
            vector<int> cur = join(vl, vr);
            for (int i = 0; i < (1 << 16); i++) {
                ans[i] = add(ans[i], cur[i]);
            }
        }
        if (s[mid] == '&' || s[mid] == '?') {
            for (int i = 0; i < (1 << 16); i++) {
                int a = ((1 << 16) - 1) ^ i;
                if (i < a) {
                    swap(vl[i], vl[a]);
                    swap(vr[i], vr[a]);
                }
            }
            vector<int> cur = join(vl, vr);
            for (int i = 0; i < (1 << 16); i++) {
                int a = ((1 << 16) - 1) ^ i;
                if (i < a) {
                    swap(cur[i], cur[a]);
                }
            }
            for (int i = 0; i < (1 << 16); i++) {
                ans[i] = add(ans[i], cur[i]);
            }
        }
    }
    return ans;
}

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%s%d", s, &n);
    int len = strlen(s);
    for (int i = 0; i < n; i++) {
        int curmask = 0;
        for (int j = 0; j < 4; j++) {
            scanf("%d", &known[i][j]);
            curmask |= (1 << j) * known[i][j];
        }
        isknown |= (1 << curmask);
        scanf("%d", &val[i]);
        istrue |= (1 << curmask) * val[i];
    }
    vector<int> v = solve(0, len);
    int ans = 0;
    for (int mask = 0; mask < (1 << 16); mask++) {
        if ((mask & isknown) == istrue) {
            ans = add(ans, v[mask]);
        }
    }
    printf("%d\n", ans);
    return 0;
}