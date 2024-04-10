#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;


int n, q;
int v[1000007], c[1000007];
VI colorAt[1000007];
int a[10000], b[10000];

int next[1000007];

long long dp[1000007];

const long long INF = 0x3f3f3f3f3f3f3fll;

int main() {
    cin >> n >> q;
    REP(i, n) {
        scanf("%d", &v[i]);
    }
    REP(i, n) {
        scanf("%d", &c[i]);
        --c[i];
        colorAt[c[i]].PB(i);
    }

    REP(i, q) {
        cin >> a[i] >> b[i];
    }

    REP(i, n) {
        next[i] = -1;
    }

    REP(i, n) {
        if (!colorAt[i].size()) {
            continue;
        }

        for (int h = colorAt[i].size() - 1; h >= 1; --h) {
            next[colorAt[i][h - 1]] = colorAt[i][h];
        }
    }

    REP(i, q) {
        REP(j, n) {
            dp[j] = b[i] * (long long)v[j];
        }

        long long maxv = -INF, nmaxv = -INF;
        int maxAt = -1, nmaxAt = -1;

        REP(j, n) {

            if (maxAt != c[j]) {
                dp[j] = max(dp[j], maxv + b[i] * (long long)v[j]);
            } else {
                dp[j] = max(dp[j], nmaxv + b[i] * (long long)v[j]);
            }

            if (next[j] != -1) {
                dp[next[j]] = max(dp[next[j]], dp[j] + a[i] * (long long)v[next[j]]);
                dp[next[j]] = max(dp[next[j]], dp[j]);
            }

            if (dp[j] > maxv) {
                if (maxAt == c[j]) {
                    maxv = dp[j];
                } else {
                    if (nmaxAt == c[j]) {
                        swap(nmaxAt, maxAt);
                        swap(maxv, nmaxv);
                        maxv = dp[j];
                    } else {
                        swap(maxv, nmaxv);
                        swap(maxAt, nmaxAt);
                        maxv = dp[j];
                        maxAt = c[j];
                    }
                }
            } else if (dp[j] > nmaxv) {
                if (maxAt == c[j]) {

                } else if (nmaxAt == c[j]) {
                    nmaxv = dp[j];
                } else {
                    nmaxv = dp[j];
                    nmaxAt = c[j];
                }
            }
        }

        long long val = 0;
        REP(j, n) {
            val = max(val, dp[j]);
        }

        cout << val << endl;
    }
/*
    REP(i, n) {
        if (!colorAt[i].size()) {
            continue;
        }

        REP(j, q) {
            dp[0][j] = -INF;
        }

        int total = 0;
        TR(it, colorAt[i]) {
            int now = total++ & 1, next = now ^ 1;
            REP(j, q) {
                dp[next][j] = max(dp[now][j], b[j] * (long long)v[*it]);
            }

            REP(j, q) {
                dp[next][j] = max(dp[next][j], a[j] * (long long)v[*it] + dp[now][j]);
            }
        }

        REP(j, q) {
            if (dp[total & 1][j] >= 0) {
                ans[j] += dp[total & 1][j];
            }
        }
    }

    REP(j, q) {
        cout << ans[j] << endl;
    }
*/

	return 0;
}