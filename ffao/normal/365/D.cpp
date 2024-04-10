#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n, d;
int dp[1130000];

int main() {
    scanf("%d %d", &n, &d);

    int s = 0;
    dp[0]=1;

    for (int i = 0; i < n; i++) {
        int ci;
        scanf("%d", &ci);
        s += ci;

        for (int v = s; v >= ci; v--) {
            dp[v] |= dp[v-ci];
        }
    }

    int lla = -1e9;
    int la = 0;
    int days = 0;

    for (int i = 1; i <= s; i++) {
        if (dp[i] && i - la <= d) {
            if (i - lla > d) {
                days++;
                lla = la;
            }
            la = i;
        }
    }
    printf("%d %d\n", la, days);
}