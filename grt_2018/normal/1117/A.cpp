#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000*100+1;
int n,m;
int a[MAXN];
int ans = 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) {
        cin>>a[i];
        m=max(m,a[i]);
    }
    int wsk = 0;
    for(int i=0; i<n;i++) {
        while(wsk+1<n&&a[wsk+1]==m) wsk++;
        if(a[i]==m) ans=max(ans,wsk-i+1);
        wsk=max(i,wsk);
    }
    cout<<ans;
    return 0;
}