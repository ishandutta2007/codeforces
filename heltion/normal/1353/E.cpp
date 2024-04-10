#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000000;
char s[maxn + 2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, k;
        cin >> n >> k >> s;
        int sum = count(s, s + n, '1'), ans = sum;
        for(int i = 0; i < k; i += 1){
            vector<int> v;
            for(int j = i; j < n; j += k) v.push_back(s[j] - '0');
            //s[L - 1] + ss - s[R] + R - L + 1 - s[R] + s[L - 1]
            //2 * s[L - 1] + ss + R - L + 1 - 2 * s[R]
            int pre = 1, pans = v.size();
            for(int j = 0; j < (int)v.size(); j += 1)
                if(j) v[j] += v[j - 1];
            for(int j = 0; j < (int)v.size(); j += 1){
                int x = v.back() + j - 2 * v[j];
                pans = min(pans, x + pre);
                pre = min(pre, 2 * v[j] - j);
            }
            ans = min(ans, pans + sum - v.back());
        }
        cout << ans << "\n";
    }
    return 0;
}