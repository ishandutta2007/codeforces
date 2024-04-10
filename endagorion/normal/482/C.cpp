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
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

string s[100];
//pii p[1500];

unsigned long long pairs[50][20];
bool nul[1 << 20];
double dp[1 << 20];
int neq[1 << 20];
unsigned long long peq[1 << 20];
int lowbit[1 << 20];

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N;
    cin >> N;
    forn(i, N) cin >> s[i];
    int L = s[0].size();
    //vector<pii> p;
    //forn(i, N) forn(j, i) p.pb(mp(i, j));
    forn(i, 1 << L) {
        if (!i) {
            lowbit[i] = -1;
            continue;
        }
        int j = 0;
        while (!((i >> j) & 1)) ++j;
        lowbit[i] = j;
    }

    forn(i, N) {
        forn(k, L) {
            forn(j, N) {
                if ((i != j) && s[i][k] == s[j][k]) pairs[i][k] += (1LL << j);
            }
        }
    }

    forn(i, N) {
        forn(j, 1 << L) {
            if (!j) peq[0] = (1LL << N) - (1LL << i) - 1;
            else {
                int k = lowbit[j];
                peq[j] = peq[j - (1 << k)] & pairs[i][k];
            }
            if (peq[j]) ++neq[j];
        }
    }

    ford(m, 1 << L) {
        dp[m] = 1.0 * neq[m];
        int ss = 0;
        forn(j, L) {
            if (!((m >> j) & 1)) ++ss;
        }
        forn(j, L) {
            if (!((m >> j) & 1)) {
                dp[m] += dp[m | (1 << j)] / ss;
            }
        }
    }

    printf("%.10lf\n", (double)dp[0] / N);

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}