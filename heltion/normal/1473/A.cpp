#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        for(int& x : v) cin >> x;
        sort(v.begin(), v.end());
        int ok = 1;
        for(int x : v) if(x > m and v[0] + v[1] > m) ok = 0;
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}