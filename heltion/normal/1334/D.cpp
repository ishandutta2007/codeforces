#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
//1 2 1 3 1 4 1 5 2 3 2 4 2 5 3 4 3 5 4 5 1
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL n, l, r;
        cin >> n >> l >> r;
        vector<LL> v;
        v.push_back(0);
        for(int i = 1; i < n; i += 1) v.push_back(2 * (n - i) + v.back());
        for(LL i = l; i <= r; i += 1){
            int p = lower_bound(v.begin(), v.end(), i) - v.begin();
            if(p == n) cout << "1 ";
            else{
                LL x = i - v[p - 1];
                if(x % 2) cout << p << " ";
                else cout << p + x / 2 << " ";
            } 
        }
        cout << "\n";
    }
    return 0;
}