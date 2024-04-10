#include<bits/stdc++.h>

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
#define rank _rank

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

const int N = 1e5 + 100;

vector<vector<int> > cycles[N];
int perm[N];
int n;
bool used[N];
vector<pair<int, int> > ans;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", perm + i);
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            vector<int> cur;
            cur.pb(i);
            used[i] = true;
            for (int j = perm[i]; j != i; j = perm[j]) {
                cur.pb(j);
                used[j] = true;
            }
            cycles[(int) cur.size()].pb(cur);
        }
    }
    bool flag = false;
    int mn = INF;
    if (cycles[1].size() >= 1) {
        mn = 1;
        flag = true;
    } else if (cycles[2].size() >= 1){
        mn = 2;
        flag = true;
        ans.eb(cycles[2][0][0], cycles[2][0][1]);
    } else {
        for (int j = 3; j <= n; j++) {
            if (cycles[j].size() >= 1) {
                mn = j;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (cycles[i].size() >= 1 && i % mn != 0) {
            flag = false;
        }
    }
    if (flag) {
        vector<int> root = cycles[mn].back();
        cycles[mn].pop_back();
        for (int i = 1; i <= n; i++) {
            for (auto v : cycles[i]) {
                for (int j = 0; j < i; j++) {
                    ans.eb(root[j % mn], v[j]);
                }
            }
        }
        printf("YES\n");
        for (auto i : ans) {
            printf("%d %d\n", i.fs, i.sc);
        }
    } else {
        printf("NO\n");
    }
    return 0;
}