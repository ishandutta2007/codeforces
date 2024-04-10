#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000*100+1;

int n,m,k;
int diff[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    int x,b;
    cin>>x;
    int ans=x;
    for(int i=0; i<n-1;i++) {
        cin>>b;
        diff[i] = b-x-1;
        x=b;
    }
    ans = b-ans+1;
    if(n==1) {cout<<"1"; return 0;}
    sort(diff,diff+n-1);
    for(int i=n-2; i>=n-k; i--) {
        ans-=diff[i];
    }
    cout<<ans;
    return 0;
}