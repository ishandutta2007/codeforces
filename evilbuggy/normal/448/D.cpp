#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

ll count(ll s, ll n, ll m){
    ll ret = 0;
    for(ll i = 1; i <= n; i++){
        ret += min(m, s/i);
    }
    return ret;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m, k;
    cin>>n>>m>>k;
    if(n > m)swap(n, m);
    ll left = 1, right = n*m;
    while(left < right){
        ll mid = left + (right - left)/2;
        ll tmp = count(mid, n, m);
        if(tmp >= k){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    cout<<left<<endl;
}