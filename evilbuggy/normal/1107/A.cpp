#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    string s;
    cin>>q;
    while(q--){
        cin>>n>>s;
        if(s.size() == 2 && s[0] >= s[1]){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            cout<<2<<endl;
            cout<<s[0]<<" "<<s.substr(1)<<endl;
        }
    }
}