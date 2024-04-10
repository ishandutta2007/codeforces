#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 300000;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 0; i < n; i += 1) cin >> a[i];
        int tans = 0;
        auto in = [&](int i){
            return i > 0 and i + 1 < n and ((a[i] > a[i - 1] and a[i] > a[i + 1]) or (a[i] < a[i - 1] and a[i] < a[i + 1]));
        };
        for(int i = 0; i < n; i += 1) tans += in(i);
        int ans = tans;
        auto ch = [&](int i, int v){
            int res = tans;
            res -= in(i - 1);
            res -= in(i);
            res -= in(i + 1);
            swap(a[i], v);
            res += in(i - 1);
            res += in(i);
            res += in(i + 1);
            swap(a[i], v);
            return res;
        };
        for(int i = 0; i < n; i += 1){
            if(i > 0){
                ans = min(ch(i, a[i - 1] + 1), ans);
                ans = min(ch(i, a[i - 1]), ans);
                ans = min(ch(i, a[i - 1] - 1), ans);
            }
            if(i + 1 < n){
                ans = min(ch(i, a[i + 1] + 1), ans);
                ans = min(ch(i, a[i + 1]), ans);
                ans = min(ch(i, a[i + 1] - 1), ans);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}