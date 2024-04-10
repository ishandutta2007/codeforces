#include <bits/stdc++.h>
using namespace std;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        if(x <= 7){
            cout<<1<<endl;
        }else if(x%2 == 0){
            cout<<x/2<<endl;
        }else{
            cout<<1 + (x-7)/2<<endl;
        }
    }
}