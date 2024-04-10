#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, l, r;
        cin >> n >> l >> r;
        map<int, int> mp;
        for(int i = 0; i < l; i += 1){
            int c;
            cin >> c;
            mp[c] += 1;
        }
        for(int i = 0; i < r; i += 1){
            int c;
            cin >> c;
            mp[c] -= 1;
        }
        vector<int> L, R;
        int Lsum = 0, Rsum = 0;
        for(auto [x, y] : mp){
            if(y > 0) L.push_back(y), Lsum += y;
            if(y < 0) R.push_back(-y), Rsum -= y;
        }
        if(Lsum < Rsum){
            swap(L, R);
            swap(Lsum, Rsum);
        }
        int d = Lsum - Rsum;
        int ans = 0;
        for(int i = 0; i < L.size(); i += 1){
            int h = min(L[i] / 2, d / 2);
            d -= 2 * h;
            ans += h;
        }
        cout << ans + Rsum + d << "\n";
    }
    return 0;
}