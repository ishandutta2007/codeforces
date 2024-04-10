#include <bits/stdc++.h>

using namespace std;

int n;
int a[16],b[16];
int best=0;

void check(int l,int r) {
    for(int i=l; i<=r; i++) {
        b[i] = a[i];
    }
    sort(b+l,b+r+1);
    bool ok=1;
    for(int i=l; i<=r;i++) {
        if(a[i]!=b[i]) ok=0;
    }
    if(ok) {
        best=max(best,r-l+1);
    }
    else {
        check(l,(l+r)/2);
        check((l+r)/2+1,r);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) {
        cin>>a[i];
    }
    check(0,n-1);
    cout<<best;
    return 0;
}