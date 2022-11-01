#include <bits/stdc++.h>

using namespace std;

string str;
int q,l,r, dp[5050][5050];
bool ispali[5050][5050];

int main() {
    cin >> str >> q;
    int n = str.size();

    for(int k=0;k<n;k++) {
        if(k && str[k] == str[k-1]) {
            ispali[k-1][k] = 1;
            dp[k-1][k] = 3;
        }
        else if(k)
            dp[k-1][k] = 2;

        ispali[k][k] = 1;
        dp[k][k] = 1;
    }
    for(int k=2;k<n;k++)
        for(int i=0; i+k <n; i++) {
            if(str[i] == str[i+k] && ispali[i+1][i+k-1])
                ispali[i][i+k] = 1;

            dp[i][i+k] = dp[i+1][i+k] + dp[i][i+k-1]
                            - dp[i+1][i+k-1] + ispali[i][i+k];
        }



    while(q--) {
        scanf("%d %d", &l, &r);
        printf("%d\n",dp[--l][--r]);
    }

    return 0;
}