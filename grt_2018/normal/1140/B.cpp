#include <bits/stdc++.h>

using namespace std;

int n,t;
const int INF = 1000*1000;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--) {
        cin>>n>>s;
        int ans = INF;
        for(int i=0; i<n;i++) {
            if(s[i]=='>') {
                ans=min(ans,i);
                break;
            }
        }
        for(int i=n-1; i>=0; i--) {
            if(s[i]=='<') {
                ans=min(ans,n-1-i);
                break;
            }
        }
        cout<<ans<<"\n";
    }
}