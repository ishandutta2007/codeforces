#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000000;
int l[maxn], r[maxn], x[maxn * 2], sum[maxn * 4 + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i += 1){
        cin >> l[i] >> r[i];
        x[i * 2] = l[i];
        x[i * 2 + 1] = r[i];
    }
    sort(x, x + 2 * n);
    int m = unique(x, x + 2 * n) - x;
    for(int i = 0; i < n; i += 1){
        int L = lower_bound(x, x + m, l[i]) - x;
        int R = lower_bound(x, x + m, r[i]) - x;
        sum[L * 2] += 1;
        sum[R * 2 + 1] -= 1;
    }
    vector<pair<int, int>> vp;
    for(int i = 0; i < 2 * m; i += 1){
        if(i) sum[i] += sum[i - 1];
        if(sum[i] >= k){
            int L = x[i / 2], R = x[(i + 1) / 2];
            if(not vp.empty() and vp.back().second == L) vp.back().second = R;
            else vp.push_back({L, R});
        }
    }
    cout << vp.size() << "\n";
    for(auto [x, y] : vp) cout << x << " " << y << "\n";
    return 0;
}