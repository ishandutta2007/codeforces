#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll b[100005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    int n, m, k;
    cin>>n>>m>>k;
    for(int i = 1; i <= n; i++){
        cin>>b[i];
    }
    vector<ll> arr;
    for(int i = 1; i < n; i++){
        arr.push_back(b[i+1] - b[i] - 1);
    }
    sort(arr.rbegin(), arr.rend());
    ll ans = n;
    while(n > k){
        ans += arr.back();
        arr.pop_back();
        n--;
    }
    cout<<ans<<endl;
}