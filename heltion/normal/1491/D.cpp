#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    for(; q; q -= 1){
        int u, v;
        cin >> u >> v;
        int ok = u <= v, sum = 0;
        for(int i = 0; i < 30; i += 1){
            sum += (u >> i) & 1 ? 1 : -1;
            sum -= (v >> i) & 1 ? 1 : -1;
            if(sum < 0) ok = 0;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}