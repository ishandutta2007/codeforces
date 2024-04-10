#include<bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main(){
    int q; cin>>q; for(int l=0; l<q; l++) {
        int n; cin>>n; int a[n+1], ans[n+1]={0}; for(int i=1; i<=n; i++) cin>>a[i]; int curr=0, cnt=0;
        for(int i=1; i<=n; i++) {
            if(!ans[i]) {
                curr=a[i]; cnt=1;
                while (curr!=i) {
                    curr=a[curr]; cnt++;
                }
                ans[i]=cnt; curr=a[curr];
                while (curr!=i) {
                    ans[curr]=cnt; curr=a[curr];
                }
            }
        }
        for(int i=1; i<=n; i++) cout<<ans[i]<<" "; cout<<endl;
    }
}