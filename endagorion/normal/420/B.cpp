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
int st[maxn];
int canbe[maxn];
char b[maxn][5];
int t[maxn];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, M;
    scanf("%d%d", &N, &M);
    forn(i, N) {
        st[i] = -1;
        canbe[i] = 1;
    }
    int unk = N, pres = 0, npres = 0;
    forn(i, M) {
        scanf("%s%d", b[i], &t[i]);
        --t[i];
        if (st[t[i]] == -1) {
            if (b[i][0] == '+') {
                st[t[i]] = 0;
                --unk;
                ++npres;
            }
            if (b[i][0] == '-') {
                st[t[i]] = 1;
                --unk;
                ++pres;
            }
        }
    }
    if (pres > 0) {
        forn(i, N) if (st[i] == 0) canbe[i] = 0;
    }
    int only = -1;
    forn(i, M) {
        if (b[i][0] == '+') {
            if (pres > 0) {
                canbe[t[i]] = 0;
            } else {
                if (only == -1 || only == t[i]) {
                    only = t[i];
                } else {
                    only = -2;
                }
            }
            st[t[i]] = 1;
            ++pres;
        }
        if (b[i][0] == '-') {
            if (pres > 1) {
                canbe[t[i]] = 0;
            } else {
                if (only == -1 || only == t[i]) {
                    only = t[i];
                } else {
                    only = -2;
                }                
            }
            st[t[i]] = 0;
            --pres;
        }
    }
    if (pres > 0) {
        forn(i, N) if (st[i] == 0) canbe[i] = 0;        
    }
    if (only != -1) {
        forn(i, N) {
            if (st[i] != -1 && i != only) canbe[i] = 0;
        }
    }
    printf("%d\n", accumulate(canbe, canbe + N, 0));
    forn(i, N) {
        if (canbe[i]) printf("%d ", i + 1);
    }
    printf("\n");

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}