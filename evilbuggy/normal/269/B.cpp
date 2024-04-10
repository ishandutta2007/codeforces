#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

int a[5005], dp[5005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin>>n>>m;
    double x;
    int ans = 1;
    for(int i = 1; i <= n; i++){
        cin>>a[i]>>x;
        dp[i] = 1;
        for(int j = 1; j < i; j++){
            if(a[j] <= a[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout<<n-ans<<endl;

}