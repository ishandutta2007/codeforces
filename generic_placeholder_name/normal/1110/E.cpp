#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n; cin>>n; ll c[n], t[n];
    for(int i=0; i<n; i++) cin>>c[i]; for(int i=0; i<n; i++) cin>>t[i];
    if(c[0]!=t[0]||c[n-1]!=t[n-1]) {
        cout<<"No"; return 0;
    }
    else {
        ll dc[n-1]; for(int i=1; i<n; i++) dc[i-1]=c[i]-c[i-1];
        ll dt[n-1]; for(int i=1; i<n; i++) dt[i-1]=t[i]-t[i-1];
        sort(dc, dc+n-1); sort(dt, dt+n-1);
        for(int i=0; i<n-1; i++) {
            if(dc[i]!=dt[i]) {
                cout<<"No"; return 0;
            }
        }
        cout<<"Yes"; return 0;
    }
}