#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int q; cin>>q; for(int l=1; l<=q; l++) {
        int n, m, tmp, p[2]={0}, q[2]={0};
        cin>>n; for(int i=0; i<n; i++) {cin>>tmp; p[tmp%2]++;}
        cin>>m; for(int i=0; i<m; i++) {cin>>tmp; q[tmp%2]++;}
        ll ans=0;
        for(int i=0; i<=1; i++) ans+=(ll)p[i]*q[i];
        cout<<ans<<endl;
    }
}