#include<bits/stdc++.h>
using namespace std;
int x,y,n,dp[2][4444444],a[1000];
const int E=100;
void Max(int &x,int y){if (x<y)x=y;}
int main(){
    cin >> n >> x >> y;
    if (x<y) swap(x,y);
    int period=x+y;
    int m=(n==22)?180:360;
    for (int i=0;i<min(m+period,n);i++){
        int o=i&1;
        for (int j=0;j<(1<<x);j++){
            Max(dp[o^1][j>>1],dp[o][j]);
            if (j&1) continue;
            if (j&(1<<(x-y))) continue;
            Max(dp[o^1][(j>>1)|(1<<(x-1))],1+dp[o][j]);
        }
        int ans=0;
        for (int j=0;j<(1<<x);j++) ans=max(ans,dp[o^1][j]);
        a[i+1]=ans;
    }
    if (n<=m) {cout << a[n] << endl;return 0;}
    int res=a[m+period]-a[m];
    int round=(n-m)/period;
    cout << a[n-round*period]+res*round << endl;
    return 0;
}