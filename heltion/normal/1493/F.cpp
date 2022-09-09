#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> vpf(int n){
    vector<pair<int, int>> res;
    for(int i = 2; i <= n; i += 1) if(n % i == 0){
        for(res.push_back({i, 0}); n % i == 0; n /= i) res.back().second += 1;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    auto vpn = vpf(n), vpm = vpf(m);
    int h = n, w = m;
    for(auto [p, r] : vpn){
        for(int ok = 1; r and ok; r -= 1){
            int nh = h / p;
            int th = nh;
            while(th * 2 <= h){
                cout << "? " << th << " " << m << " " << 1 << " " << 1 << " " << th + 1 << " " << 1 << endl;
                cin >> ok;
                if(not ok) break;
                th *= 2;
            }
            if(ok and th < h){
                cout << "? " << h - th << " " << m << " " << 1 << " " << 1 << " " << th + 1 << " " << 1 << endl;
                cin >> ok;
                if(not ok) break;
            }
            if(ok) h = nh;
        }
    }
    for(auto [p, r] : vpm){
        for(int ok = 1; r and ok; r -= 1){
            int nw = w / p;
            int tw = nw;
            while(tw * 2 <= w){
                cout << "? " << n << " " << tw << " " << 1 << " " << 1 << " " << 1 << " " << tw + 1 << endl;
                cin >> ok;
                if(not ok) break;
                tw *= 2;
            }
            if(ok and tw < w){
                cout << "? " << n << " " << w - tw << " " << 1 << " " << 1 << " " << 1 << " " << tw + 1 << endl;
                cin >> ok;
                if(not ok) break;
            }
            if(ok) w = nw;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i += 1) for(int j = 1; j <= m; j += 1)
        if(n % i == 0 and i % h == 0 and m % j == 0 and j % w == 0)
            ans += 1;
    cout << "! " << ans << endl;
    return 0;
}