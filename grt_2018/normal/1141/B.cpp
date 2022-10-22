#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2*1000*100;
int n,ans=0;
bool t[3*MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) {
        cin>>t[i];
        t[i+n] = t[i+2*n] = t[i];
    }
    int x=0;
    for(int i=0; i<3*n;i++) {
        ans=max(ans,x);
        if(t[i]==0) {
            x=-1;
        }
        x++;
    }
    cout<<ans;
    return 0;
}