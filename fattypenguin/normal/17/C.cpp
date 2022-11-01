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

const int MOD = 51123987;

int dp[2][151][55][55];
int first[151][3];
string s;

inline void addMod(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main() {
    int n;

    cin >> n >> s;

    int amount = (n + 2) / 3 + 2;

    FILL(first, 0x7f);
    for (int i = n - 1; i >= 0; --i) {
        REP(j, 3) {
            if (s[i] == j + 'a') {
                first[i][j] = i;
            } else {
                first[i][j] = first[i + 1][j];
            }
        }
    }

    REP(j, 3) {
        if (first[0][j] < n) {
            dp[0][first[0][j]][j == 0][j == 1] = 1;
        }
    }

    int step = 0;

    REP(i, n - 1) {

        int now = step++ & 1,
            next = now ^ 1;

        FILL(dp[next], 0);

        REP(j, n) {
            REP(k, amount + 1) REP(r, amount + 1) {

                if (dp[now][j][k][r] == 0) {
                    continue;
                }

                if (k + (s[j] == 'a') <= amount && r + (s[j] == 'b') <= amount && i + 1 - k - r + (s[j] == 'c') <= amount) {
                    addMod(dp[next][j][k + (s[j] == 'a')][r + (s[j] == 'b')], dp[now][j][k][r]);
                }

                REP(nc, 3) {
                    if (nc == s[j] - 'a') {
                        continue;
                    }

                    if (first[j][nc] < n) {
                        if (k + (nc == 0) <= amount && r + (nc == 1) <= amount && i + 1 - k - r + (nc == 2) <= amount) {
                            addMod(dp[next][first[j][nc]][k + (nc == 0)][r + (nc == 1)], dp[now][j][k][r]);
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    REP(j, n) REP(k, amount + 1) REP(r, amount + 1) {
        int x = k,
            y = r,
            z = n - x - y;

        if (abs(x - y) <= 1 && abs(y - z) <= 1 && abs(x - z) <= 1) {
            addMod(ans, dp[(n-1)&1][j][k][r]);
        }
    }

    cout << ans << endl;
	return 0;
}