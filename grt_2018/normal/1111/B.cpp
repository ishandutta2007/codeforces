#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100*1000+1;

int n,k,m;
int a[MAXN];
long long pref[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k>>m;
    for(int i=1; i<=n;i++) {cin>>a[i];}
    a[0] = 0;
    sort(a,a+n+1);
    for(int i=1; i<=n;i++) {pref[i]=pref[i-1]+a[i];}
    long double ans=0;
    for(int i=0; i<=m;i++) {
        if(i<n) {
            long long s = pref[n] - pref[i];
            s+=min((long long)m-i,(long long)k*(n-i));
            ans = max(ans, ( long double) s / (n-i));
        }
        else break;
    }
    cout<<setprecision(10)<<ans;
    return 0;
}