#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int& x : v) cin >> x;
        int ok = 0;
        for(int i = 1; i < n; i += 1) if(v[i] >= v[i - 1]) ok = 1;
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}