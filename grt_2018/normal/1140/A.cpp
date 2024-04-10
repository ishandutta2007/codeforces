#include <bits/stdc++.h>

using namespace std;

int n,ans;
int a[1000*10+1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int wsk = 1;
    for(int i=1; i<=n;i++) cin>>a[i];
    for(int i=1; i<=n;i++) {
        wsk=max(wsk,a[i]);
        while(i<=n&&i<wsk) {
            i++;
            wsk=max(wsk,a[i]);
        }
        ans++;
    }
    cout<<ans;
}