#include <bits/stdc++.h>

#define MN 100100
#define MAX 9999999999999999
#define debug(a) cout << a << endl

using namespace std;

long long n, c[MN], dp[MN][2];
char strc[MN];
vector <string> dic, dicr;

int main() {
    scanf("%lld",&n);

    for(int i=0; i<n; i++) {
        scanf("%lld",&c[i]);
    }

    for(int i=0; i<n; i++) {
        scanf("%s",strc);
        string st = strc;
        dic.push_back(st);
        reverse(st.begin(),st.end());
        dicr.push_back(st);
    }

    dp[0][0] = 0;
    dp[0][1] = c[0];

    for(int i=1;i<n;i++) {
        dp[i][0] = dp[i][1] = MAX;

        if(dic[i] >= dic[i-1]) dp[i][0] = dp[i-1][0];
        if(dic[i] >= dicr[i-1])dp[i][0] = min(dp[i][0], dp[i-1][1]);

        if(dicr[i] >= dic[i-1] && dp[i-1][0] != MAX) dp[i][1] = dp[i-1][0] + c[i];
        if(dicr[i] >= dicr[i-1] && dp[i-1][1]!= MAX) dp[i][1] = min(dp[i][1], dp[i-1][1] + c[i]);
    }

    long long ans = min(dp[n-1][0], dp[n-1][1]);
    if(ans >= MAX) printf("-1\n");
    else printf("%lld\n",ans);

    return 0;
}