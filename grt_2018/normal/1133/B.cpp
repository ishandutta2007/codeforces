#include <bits/stdc++.h>

using namespace std;

int n,k;
int cnt[101];
int ans=0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int a,i=0; i<n;i++) {
        cin>>a;
        cnt[a%k]++;
    }
    ans = cnt[0]/2;
    for(int i=1; i<k;i++) {
        if(k-i<i) break;
        if(k-i==i) ans+=cnt[i]/2;
        else
        ans+=min(cnt[i],cnt[k-i]);
    }
    cout<<ans*2;
    return 0;
}