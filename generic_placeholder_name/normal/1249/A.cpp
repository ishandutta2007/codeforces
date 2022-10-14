#include<bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main(){
    int q; cin>>q; while(q--) {
        int n; cin>>n; int a[n]; for(int i=0; i<n; i++) cin>>a[i]; sort(a, a+n); bool c=0;
        for(int i=1; i<n; i++) {
            if(a[i]==a[i-1]+1) c=1;
        }
        cout<<(c==0?1:2)<<endl;
    }
}