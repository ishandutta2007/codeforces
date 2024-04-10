#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 500000;
int p[maxn], q[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, m = 0;
        cin >> n;
        map<int, int, greater<int>> mp;
        for(int i = 1; i <= n; i += 1){
            cin >> p[i];
            mp[p[i]] += 1;
        }
        for(auto p : mp) q[m += 1] = p.second;
        int g = q[1], s = 0, b = 0, k = 2;
        while(s <= g and k <= m) s += q[k], k += 1;
        while(b <= g and k <= m) b += q[k], k += 1;
        if(s <= g or b <= g or (g + b + s) * 2 > n) cout << "0 0 0\n";
        else{
            while(k <= m and (g + s + b + q[k]) * 2 <= n) b += q[k], k += 1;
            cout << g << " " << s << " " << b << "\n";
        }
    }
    return 0;
}