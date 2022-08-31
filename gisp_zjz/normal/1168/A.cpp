#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+7;
int dp[maxn],l,r,mid,n,a[maxn],m;
bool check(int x){
    if (a[1]+x>=m) dp[1]=0; else dp[1]=a[1];
    for (int i=2;i<=n;i++){
        if (a[i]+x<m){
            if (a[i]+x<dp[i-1]) return false;
            dp[i]=max(dp[i-1],a[i]);
        } else {
            int p=a[i]+x-m;
            if (p>=dp[i-1]) dp[i]=dp[i-1];
            else dp[i]=max(dp[i-1],a[i]);
        }
    }
    return true;
}
int main(){
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    l=-1; r=m-1;
    while (r-l>1){
        mid=(l+r)>>1;
        if (check(mid)) r=mid; else l=mid;
    }
    cout << r << endl;
    return 0;
}