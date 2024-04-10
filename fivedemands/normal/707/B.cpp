#include<iostream>
using namespace std;
int a[100001];
int main(){
    ios::sync_with_stdio(false);
    int n,m,k,t;
    cin >> n >> m >> k;
    int p[m+1],q[m+1],r[m+1];
    int ans=2e9;
    for(int i=1; i<=m ;i++){
        cin >> p[i] >> q[i] >> r[i];
    }
    for(int i=1; i<=k ;i++){
        cin >> t;
        a[t]=true;
    }
    for(int i=1; i<=m ;i++){
        if(a[p[i]]+a[q[i]]==1) ans=min(ans,r[i]);
    }
    if(ans==2e9) cout << -1 << endl;
    else cout << ans << endl;
}