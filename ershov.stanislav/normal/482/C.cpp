#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

#define ll long long
#define ld long double

int n, len, cnt[1111111];
char s[55][22];
ll dp[1111111];
long double ans[1111111];

int main() {
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    for (int i=0; i<n; i++) cin >> s[i];
    len=strlen(s[0]);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) if (j!=i) {
            int f=0;
            for (int k=0; k<len; k++) if (s[i][k]==s[j][k]) f^=1<<k;
            dp[f]|=(1ll)<<i;
        }
    }
    for (int i=(1<<len)-1; i>=0; i--) {
        for (int j=0; j<20; j++) {
            dp[i&(i^(1<<j))]|=dp[i];
        }
        for (int j=0; j<55; j++) if (dp[i]&((1ll)<<j)) cnt[i]--;
        cnt[i]+=n;
    }
    for (int i=(1<<len)-2; i>=0; i--) {
        int cc=0;
        for (int j=0; j<len; j++) if (!(i&(1<<j))) ans[i]+=ans[i|(1<<j)], cc++;
        ans[i]/=cc;
        ans[i]+=1;
        ans[i]-=((long double)cnt[i])/n;
    }
    cout << fixed;
    cout << setprecision(20);
    cout << ans[0];
    return 0;
}