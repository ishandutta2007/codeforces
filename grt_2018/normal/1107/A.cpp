#include <bits/stdc++.h>

using namespace std;

int q,n;
string s;

void Solve() {
    cin>>n>>s;
    if(n==2&&(int)s[0]>=(int)s[1]) {
        cout<<"NO\n"; return;
    }
    cout<<"YES\n2\n"<<s[0]<<" ";
    for(int i=1; i<n;i++) {
        cout<<s[i];
    }
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>q;
    while(q--) {
        Solve();
    }
    return 0;
}