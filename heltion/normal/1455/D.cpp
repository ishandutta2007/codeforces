#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for(int& a : v) cin >> a;
        int ok = 1;
        for(int i = 1; i < n; i += 1) ok &= v[i] >= v[i - 1];
        if(ok){
            cout << "0\n";
            continue;
        }
        int ans = n + 1;
        for(int i = 0; i < n; i += 1){
            vector<int> w;
            for(int j = 0; j < n; j += 1) if(i != j) w.push_back(v[j]);
            w.push_back(x);
            sort(w.begin(), w.end());
            int ok = 1;
            vector<int> p;
            for(int j = 0; j < n; j += 1){
                if(w[j] < v[j]) p.push_back(j);
                if(w[j] > v[j]) ok = 0;
            }
            ok &= not p.empty();
            if(not ok) continue;
            ok &= w[p[0]] == x and p.back() == i;
            for(int j = 1; j < p.size(); j += 1) ok &= w[p[j]] == v[p[j - 1]];
            if(ok) ans = min(ans, (int)p.size());
        }
        if(ans > n) cout << "-1\n";
        else cout << ans << "\n";
    }
    return 0;
}