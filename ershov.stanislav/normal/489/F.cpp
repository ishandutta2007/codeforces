#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <string>
#include <cstring>

#define fs first
#define sc second
#define mp make_pair
#define pb push_back

#ifdef DEBUG
#define dout(x) cerr << x
#else
#define dout(x)
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1e9+100;
const ll lINF = 1e18;
const double E = 2.718281828459045;

int n, m, cnt[555];
long long mod, dp[555][555];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> m >> mod;
    dp[n][n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <=n; j++) {
            long long c1 = i*2 - j*2, c2 = n-j-c1;
            dp[i][j] = (c1*(c1-1)/2*dp[i+1][j+2] + c2*(c2-1)/2*dp[i+1][j]
                    +c1*c2*dp[i+1][j+1])%mod;
            //dout(dp[i][j] << ' ');
        }
        //dout(endl);
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') cnt[j]++;
        }
    }
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        cnt1 += (cnt[i] == 2);
    }
    cout << dp[m][cnt1] << endl;
    return 0;
}