#include <bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main() {
    int n, m, d; cin>>n>>m>>d; int c[m+1]={0}, ans[n+1]={0};
    int pos=0;
    for(int i=1; i<=m; i++) {
        pos+=d; cin>>c[i]; pos+=c[i]-1;
    }
    pos+=d;
    if(pos<n+1) {cout<<"NO"; return 0;}
    cout<<"YES\n";
    pos=0; int sum=0;
    for(int i=1; i<=m; i++) sum+=c[i];
    for(int i=1; i<=m; i++) {
        if (pos+d+sum-1<=n) pos+=d; else pos=n-sum+1;
        for(int j=pos; j<=pos+c[i]-1; j++) ans[j]=i;
        pos+=c[i]-1; sum-=c[i];
    }
    for (int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
}