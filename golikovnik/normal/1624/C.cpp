#include<bits/stdc++.h>
using namespace std;

void solve(){
    mt19937 rng(566);
    int n;
    cin >> n;
    vector<int>a(n), used(n + 1, false);
    for(auto &i : a) cin >> i;
    shuffle(a.begin(), a.end(), rng);
    bool ok = true;
    for(auto &i : a){
        int x = i;
        while(x > n or used[x])  x /= 2;
        if(x > 0) used[x] = true;
        else ok = false;
    }
    cout << (ok ? "YES" : "NO") << '\n';

}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}