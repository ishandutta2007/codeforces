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
        int m = *min_element(v.begin(), v.end());
        vector<int> u, w;
        for(int i = 0; i < n; i += 1) if(v[i] % m == 0){
            u.push_back(v[i]);
            w.push_back(i);
        }
        sort(u.begin(), u.end());
        for(int i = 0; i < (int)u.size(); i += 1) v[w[i]] = u[i];
        int ok = 1;
        for(int i = 1; i < n; i += 1) if(v[i] < v[i - 1]) ok = 0;
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}