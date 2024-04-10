#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1001;
int n;
int t[MAXN];
map<int,int>m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) {
        cin>>t[i];
    }
    for(int i=0; i<n;i++) {
        for(int j=i+1; j<n;j++) {
            m[t[i]+t[j]]++;
        }
    }
    int ans=0;
    for(auto it:m) {
        ans=max(ans,it.second);
    }
    cout<<ans;
    return 0;
}