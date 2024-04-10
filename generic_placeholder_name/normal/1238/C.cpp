#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int q; cin>>q; for(int l=1; l<=q; l++) {
        int h, n; cin>>h>>n; int a[n]; for(int i=0; i<n; i++) cin>>a[i]; a[n]=0;
        int ans=0;
        for(int i=0; i<n-1; i++) {
            if(a[i+2]==a[i+1]-1) i++; else ans++;
        }
        cout<<ans<<endl;
    }
}