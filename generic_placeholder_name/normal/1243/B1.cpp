#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool solve(string a, string b) {
    int diff=0; char x, y;
    for(int i=0; i<a.length(); i++) {
        if(a[i]!=b[i]) if(diff==0) {diff++; x=a[i]; y=b[i];}
        else if(diff==1) {diff++; if(a[i]!=x||b[i]!=y) return 0;}
        else return 0;
    }
    return diff!=1;
}

int32_t main() {
    int q; cin>>q; while(q--) {
        int n; string a, b; cin>>n>>a>>b;
        cout<<(solve(a, b)?"Yes\n":"No\n");
    }
}