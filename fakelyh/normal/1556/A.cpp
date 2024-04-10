#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,c,d;
signed main(){
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>c>>d;
        if((c-d)&1)cout<<"-1\n";
        else cout<<(c==d?(!c?0:1):2)<<endl;
    }
    return 0;
}