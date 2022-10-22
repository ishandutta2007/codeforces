#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <random>
#include <time.h>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 5e4;
int nxt[MAXN];
int prv[MAXN];
int dp[57][MAXN];                
int n;

void calc(int k, vector <pair <int, int>> a, vector <pair <int, int>> b, int h) {
    if (b.size() == 0) return;

    vector <pair <int, int>> na, nb;

    int curr = 1;
    int cl = n - 1, cr = n - 1;
    for (int i = b.size() - 1; i >= 0; --i) {
        int tl = b[i].first;
        int tr = b[i].second;
        int tm = (tl + tr) / 2;

        int l = a[i].first;
        int r = a[i].second;

        while (tm < cl) {
            --cl;
            curr += (cr < nxt[cl]);
        }

        while (tm < cr) {
            curr -= (prv[cr] < cl); 
            --cr;
        }
        
        int ans = curr + dp[k - 1][cl];
        int best = cl;
        while (l < cl) {
            --cl;
            curr += (cr < nxt[cl]);

            if (ans < dp[k - 1][cl] + curr) {
                ans = dp[k - 1][cl] + curr;
                best = cl;
            }
        }
        
        dp[k][tm + 1] = ans;

        if (tm + 1 <= tr) {
            na.push_back({best, r});
            nb.push_back({tm + 1, tr});
        }

        if (tl <= tm - 1) {
            na.push_back({l, best});
            nb.push_back({tl, tm - 1});
        }
    }

    reverse(na.begin(), na.end());
    reverse(nb.begin(), nb.end());

    calc(k, na, nb, h + 1);
}

signed main() {
    ios_base::sync_with_stdio(false);

    int k;
    cin >> n >> k;

    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    map <int, int> ms1;
    for (int i = n - 1; i >= 0; --i) {
        if (ms1.find(a[i]) == ms1.end()) nxt[i] = INF;
        else nxt[i] = ms1[a[i]];
        ms1[a[i]] = i;
    }

    map <int, int> ms2;
    for (int i = 0; i < n; ++i) {
        if (ms2.find(a[i]) == ms2.end()) prv[i] = -1;
        else prv[i] = ms2[a[i]];
        ms2[a[i]] = i;
    }
    
    for (int i = 0; i < 57; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            dp[i][j] = -INF;
        }
    }
    
    dp[0][0] = 0;
    for (int i = 1; i <= k; ++i) {
        vector <pair <int, int>> f;
        f.push_back({0, n - 1});

        vector <pair <int, int>> s;
        s.push_back({0, n - 1});

        calc(i, f, s, 0);
    }

    cout << dp[k][n] << '\n';

    return 0;
}