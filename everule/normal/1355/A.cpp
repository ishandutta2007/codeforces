#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
void solve(){
    ll n,k;
    cin>>n>>k;
    while(--k){
        ll N=n;
        ll mn=10, mx=-1;
        while(N){
            mx=max(mx, N%10);
            mn=min(mn, N%10);
            N/=10;
        }
        if(mn==0){
            break;
        }
        n+=mn*mx;
    }
    cout<<n<<"\n";
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