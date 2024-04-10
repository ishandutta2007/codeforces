#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
void solve(){
    int n;
    cin>>n;
    int e = (n+3)/4;
    n = n - e;
    for(int i=0;i<n;i++){
        cout<<"9";
    }
    for(int i=0;i<e;i++){
        cout<<"8";
    }
    cout<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}