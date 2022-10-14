#include <bits/stdc++.h>
#define ll long long
using namespace std;

int solve(int a[], int n) {
    int pf[n+2]={0}; for(int i=n; i>=0; i--) pf[i]=pf[i+1]+a[i];
    for(int i=n; i>=0; i--) if(pf[i]>=i) return i;
}

int32_t main() {
    int q; cin>>q; while(q--) {
        int n, tmp; cin>>n; int a[n+1]={0}; for(int i=0; i<n; i++) {cin>>tmp; a[tmp]++;}
        cout<<solve(a, n)<<endl;
    }
}