#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int& a : v) cin >> a;
        sort(v.begin(), v.end());
        int ok = 1;
        for(int i = 1; i < n; i += 1) ok &= v[i] - v[i - 1] <= 1;
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}