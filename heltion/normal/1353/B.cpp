#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for(int& x : a) cin >> x;
        for(int& x : b) cin >> x;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());
        int res = 0;
        for(int i = 0; i < n; i += 1){
            if(i < k) res += max(a[i], b[i]);
            else res += a[i];
        }
        cout << res << "\n";
    }
    return 0;
}