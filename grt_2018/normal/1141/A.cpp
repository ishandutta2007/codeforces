#include <bits/stdc++.h>

using namespace std;

int n,m,ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    if(m%n!=0) {
        cout<<"-1";
        return 0;
    }
    m=m/n;
    while(m%2==0) {
        ans++;
        m/=2;
    }
    while(m%3==0) {
        ans++;
        m/=3;
    }
    if(m>1) cout<<"-1";
    else cout<<ans;
    return 0;
}