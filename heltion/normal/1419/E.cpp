#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -=1){
        int n;
        cin >> n;
        vector<int> v;
        for(int d = 1; d * d <= n; d += 1) if(n % d == 0){
            if(d != 1) v.push_back(d);
            if(d * d != n) v.push_back(n / d);
        }
        vector<pair<int, int>> vp;
        int m = n;
        for(int p = 2; p * p <= m; p += 1) if(m % p == 0)
            for(vp.push_back({p, 0}); m % p == 0; m /= p) vp.back().second += 1;
        if(m > 1) vp.push_back({m, 1});
        if(vp.size() == 1){
            for(int d : v) cout << d << " ";
            cout << "\n0\n";
            continue;
        }
        if(vp.size() == 2 and vp[0].second == 1 and vp[1].second == 1){
            for(int d : v) cout << d << " ";
            cout << "\n1\n";
            continue;
        }
        vector<int> w(v.size());
        if(vp.size() == 2){
            for(int j = 0; j < v.size(); j += 1) if(not w[j] and v[j] % vp[0].first == 0 and v[j] != vp[0].first * vp[1].first and v[j] != n){
                w[j] = 1;
                cout << v[j] << " ";
            }
            cout << vp[0].first * vp[1].first << " ";
            for(int j = 0; j < v.size(); j += 1) if(not w[j] and v[j] % vp[1].first == 0 and v[j] != vp[0].first * vp[1].first and v[j] != n){
                w[j] = 1;
                cout << v[j] << " ";
            }
            cout << n << "\n0\n";
            continue;
        }
        for(int i = 0; i < vp.size(); i += 1){
            for(int j = 0; j < v.size(); j += 1) if(not w[j] and v[j] % vp[i].first == 0 and v[j] != vp[i].first * vp[(i + 1) % vp.size()].first and v[j] != vp[i].first * vp[(i + vp.size() - 1) % vp.size()].first){
                w[j] = 1;
                cout << v[j] << " ";
            }
            cout <<  vp[i].first * vp[(i + 1) % vp.size()].first << " ";
        }
        cout << "\n0\n";
    }
    return 0;
}