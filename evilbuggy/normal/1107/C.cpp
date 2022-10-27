#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

int a[200005];
ll dp[200005], sum[200005];
string s;
ll ans;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin>>n>>k;

    for(int i = 0; i < n; i++){
        cin>>a[i];
        sum[i] = (i == 0)?a[0]:(sum[i-1] + a[i]);
    }
    cin>>s;
    int l = 0, r = 0;
    ans = 0;
    while(l < n){
        r = l;
        while(r < n && s[l] == s[r]){
            r++;
        }
        r--;
        if(r-l+1 <= k){
            ans += sum[r];
            if(l != 0)ans -= sum[l-1];
        }else{
            sort(a + l, a + r + 1);
            for(int i = r; i >= r-k+1; i--){
                ans += a[i];
            }
        }
        l = r+1;
    }
    cout<<ans<<endl;

}