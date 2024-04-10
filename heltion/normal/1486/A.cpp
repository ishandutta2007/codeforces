#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<LL> h(n);
        for(LL& x : h) cin >> x;
        LL s = 0, ok = 1;
        for(int i = 0; i < n; i += 1){
            h[i] += s;
            if(h[i] < i) ok = 0;
            s = h[i] - i;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}