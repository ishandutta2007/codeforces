#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
void solve(){
    int n,k;
    cin>>n>>k;
    int mnput = 0, mxput = n;
    auto getcandies = [&](ll x){
        return x*(x+1)/2 - (n-x);
    };
    int ans = -1;
    while(mnput <= mxput){
        int mid = mnput + mxput;
        mid/=2;
        ll candies = getcandies(mid);
        if(candies<k){
            mnput = mid + 1;
        }
        else if(candies>k){
            mxput = mid - 1;
        }
        else{
            ans = mid;
            break;
        }
    }
    //assert(ans!=-1);
    cout<<(n - ans)<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}