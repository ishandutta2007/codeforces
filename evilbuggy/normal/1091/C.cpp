#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll compute(ll n, ll k){
    ll r = (n-1)/k;
    return r + 1 + r*(r+1)/2*k;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    vector<int> primes;
    ll t = n;
    set<ll> arr;
    for(int i = 1; i <= 100005; i++){
        if(n%i == 0){
            arr.insert(compute(n, i));
            arr.insert(compute(n, n/i));
        }
    }
    for(set<ll>::iterator it = arr.begin(); it != arr.end(); it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;
}