#include<bits/stdc++.h>
using namespace std;

const int INF = 10000;
int n, k;
char arr[2010][2010];
int dp[2010][2010];
int dp2[2010][2010];
pair<int,int> r[2010], c[2010];
int ans;
int cnt;

int main(){
    scanf("%d%d", &n, &k);

    for(int i=0; i<n; i++) {
        scanf("%s", arr[i]);
    }

    for(int i=0; i<n; i++) {
        r[i].first = INF;
        c[i].first = INF;
    }

    for(int i=0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            if(arr[i][j] == 'B') {
                r[i].first = min(r[i].first, j);
                r[i].second = max(r[i].second, j);
                c[j].first = min(c[j].first, i);
                c[j].second = max(c[j].second, i);
            }
        }
    }

    for(int i=0; i<n; i++) {
        if(r[i].first == INF) cnt++;
        if(c[i].first == INF) cnt++;
    }

    for(int i=0; i+k-1<n; i++) {
        for(int j=0; j<k; j++) {
            if(i <= c[j].first && c[j].second - k + 1 <= i && c[j].first != INF) dp[i][0]++;
        }
    }

    for(int i=0; i+k-1<n; i++) {
        for(int j=1; j+k-1<n; j++) {
            dp[i][j] = dp[i][j-1];
            if(i <= c[j-1].first && c[j-1].second- k + 1 <= i && c[j-1].first != INF) {
                dp[i][j]--;
            }
            if(i <= c[j+k-1].first && c[j+k-1].second - k + 1 <= i && c[j+k-1].first != INF) {
                dp[i][j]++;
            }
        }
    }

    for(int j=0; j+k-1<n; j++) {
        for(int i=0; i<k; i++) {
            if(j <= r[i].first && r[i].second - k + 1 <= j && r[i].first != INF) dp2[0][j]++;
        }
    }

    for(int j=0; j+k-1<n; j++) {
        for(int i=1; i+k-1<n; i++) {
            dp2[i][j] = dp2[i-1][j];
            if(j <= r[i-1].first && r[i-1].second- k + 1<=j && r[i-1].first != INF) {
                dp2[i][j]--;
            }
            if(j <= r[i+k-1].first && r[i+k-1].second - k + 1 <= j && r[i+k-1].first != INF) {
                dp2[i][j]++;
            }
        }
    }

    for(int i=0; i+k-1<n; i++) {
        for(int j=0; j+k-1<n; j++) {
            ans = max(ans, dp[i][j] + dp2[i][j]);
            //printf("%d-%d ", dp[i][j], dp2[i][j]);
        }
        //printf("\n");
    }

    printf("%d", cnt+ans);
}