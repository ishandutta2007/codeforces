#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, k;
        cin >> n >> k;
        vector<int> sum(2 * k + 2, 0), v(n);
        for(int i = 0; i < n; i += 1) cin >> v[i];
        for(int i = 0; i < n / 2; i += 1){
            sum[min(v[i], v[n - 1 - i]) + 1] += 1;
            sum[max(v[i], v[n - 1 - i]) + k + 1] -= 1;
            sum[v[i] + v[n - 1 - i]] += 1;
            sum[v[i] + v[n - 1 - i] + 1] -= 1;
        }
        partial_sum(sum.begin(), sum.end(), sum.begin());
        cout << n - *max_element(sum.begin(), sum.end()) << "\n";
    }
    return 0;
}