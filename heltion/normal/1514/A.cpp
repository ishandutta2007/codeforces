#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    set<int> s;
    for(int i = 1; i <= 100; i += 1) s.insert(i * i);
    for(cin >> t; t; t -= 1){
        int n, a, ok = 0;
        for(cin >> n; n; n -= 1){
            cin >> a;
            ok = ok or not s.count(a);
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}