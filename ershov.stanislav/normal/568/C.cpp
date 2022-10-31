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

const int N = 4444;
const int MOD = 1e9 + 7;

char tp[300];
int l, n, m;
vector<pair<int, int> > graph[222][3];
char s[222];
int types[222];
bool flag = false;
bool ret = false;
vector<char> interesting;
vector<pair<int, int> > changes;

void dfs(int v, int c) {
    if (types[v] != 0 && types[v] != c) {
        flag = true;
    } else {
        if (!types[v]) {
            types[v] = c;
            changes.eb(v, c);
        } else {
            return;
        }
        for (auto i : graph[v][c]) {
            dfs(i.fs, i.sc);
        }
    }
}

void dp(int i) {
    if (i == n) {
        printf("%s\n", s);
        ret = true;
        return;
    }
    for (auto nxt : interesting) {
        flag = false;
        s[i] = nxt;
        changes.clear();
        dfs(i, tp[nxt - 'a']);
        if (!flag) {
            dp(i + 1);
            if (ret) {
                return;
            }
        } else {
            for (auto i : changes) {
                types[i.fs] = 0;
            }
        }
    }
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%s", tp);
    l = strlen(tp);
    interesting.pb('a');
    for (int i = 0; i < l; i++) {
        if (tp[i] != tp[0]) {
            interesting.pb(i + 'a');
            break;
        }
    }
    for (int i = 0; i < l; i++) {
        if (tp[i] == 'V') {
            tp[i] = 1;
        } else {
            tp[i] = 2;
        }
    }
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int pos1, pos2;
        char t1, t2;
        scanf(" %d %c %d %c", &pos1, &t1, &pos2, &t2);
        pos1--, pos2--;
        if (t1 == 'V') {
            t1 = 1;
        } else {
            t1 = 2;
        }
        if (t2 == 'V') {
            t2 = 1;
        } else {
            t2 = 2;
        }
        graph[pos1][t1].eb(pos2, t2);
        graph[pos2][3 - t2].eb(pos1, 3 - t1);
    }
    for (int i = 0; i < n; i++) {
        bool flag2 = false;
        for (int j = 1; j <= 2; j++) {
            for (int r = 0; r < n; r++) {
                types[r] = 0;
            }
            flag = false;
            changes.clear();
            dfs(i, j);
            if (!flag) {
                flag2 = true;
            }
        }
        if (!flag2) {
            printf("-1\n");
            return 0;
        }
    }
    scanf(" %s", s);
    for (int i = n; i >= 0; i--) {
        vector<int> v(3);
        for (char j = (i < n) ? s[i] + 1 : 'a' + l - 1; j <= 'a' + l - 1; j++) {
            if (v[tp[j - 'a']] != 0) {
                continue;
            }
            v[tp[j - 'a']]++;
            int pref = i;
            if (i < n) {
                pref++;
            }
            if (i < n) {
                s[i] = j;
            }
            for (int i = 0; i < n; i++) {
                types[i] = 0;
            }
            flag = false;
            for (int i = 0; i < pref; i++) {
//                cout << (int)tp[s[i] - 'a'] << endl;
                dfs(i, tp[s[i] - 'a']);
            }
            if (!flag) {
                dp(pref);
                if (ret) {
                    return 0;
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}