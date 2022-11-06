#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
signed main(){
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        if(n%2==0)cout<<"0 0 "<<n/2<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}