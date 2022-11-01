#include <bits/stdc++.h>
using namespace std;
main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int T; cin>>T; while(T--){
        int a,b; cin>>a>>b;
        if(a==1){
            cout<<(a==b?"YES\n":"NO\n");
        } else if(a==2 || a==3){
            cout<<(b<=3?"YES\n":"NO\n");
        } else{
            cout<<"YES\n";
        }
    }
}