#include <bits/stdc++.h>

using namespace std;

int n;
int cntp,cntm;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int a,i=0; i<n;i++) {
        cin>>a;
        if(a>0) cntp++;
        if(a<0) cntm++;
    }
    if(cntp>=(n-1)/2+1) cout<<"1";
    else if(cntm>=(n-1)/2+1) cout<<"-1";
    else cout<<"0";
    return 0;
}