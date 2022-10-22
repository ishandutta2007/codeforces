#include <bits/stdc++.h>

using namespace std;

int n;
int a[2*1000*100+1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) cin>>a[i];
    sort(a,a+n);
    int wsk=0;
    int ans = 0;
    for(int i=0; i<n;i++) {
        while(wsk+1<n&&a[wsk+1]-a[i]<=5)
            wsk++;
        ans = max(ans,wsk-i+1);
    }
    cout<<ans;
    return 0;
}