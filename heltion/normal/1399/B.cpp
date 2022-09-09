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
        vector<LL> a(n), b(n);
        for(LL& x : a) cin >> x;
        for(LL& x : b) cin >> x;
        LL ma = *min_element(a.begin(), a.end()), mb = *min_element(b.begin(), b.end()), res = 0;
        for(int i = 0; i < n; i += 1) res += max(a[i] - ma, b[i] - mb);
        cout << res << "\n";
    }
    return 0;
}