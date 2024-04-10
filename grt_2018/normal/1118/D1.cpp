#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2*100000+1;

int n,m;
int a[MAXN];

bool checkw(int b) {
    long long s=0;
    for(int i=0; i<n;i++) {
        s+=max(0,a[i]-(i/b));
    }
    if(s>=m) return 1;
    return 0;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n); reverse(a,a+n);
    int pocz=1, kon = n,sr;
    int ans = -1;
    while(pocz<=kon) {
        sr=(pocz+kon)/2;
        if(checkw(sr)) {ans= sr; kon=sr-1;}
        else pocz=sr+1;
    }
    cout<<ans;
}