#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int ok = 0;
        for(int i = 1; i <= k and not ok; i += 1){
            vector<int> v(1 << i);
            vector<int> ig(n + 1);
            for(int j = 0; j < n; j += 1){
                if(s[j] == '0'){
                    int L = max(j - (k - i) + 1, 0);
                    ig[L] += 1;
                    ig[j + 1] -= 1;
                }
            }
            partial_sum(ig.begin(), ig.end(), ig.begin());
            int sum = 0;
            for(int j = 0; j < i; j += 1) sum = (sum << 1) | (s[k - i + j] - '0');
            if(not ig[0]) v[sum] = 1;
            //cout << i << " " << 0 << " " << sum << "\n";
            for(int j = 1; j <= n - k; j += 1){
                sum = (sum << 1) & ~(1 << i);
                sum |= s[j + k - 1] - '0';
                if(not ig[j]) v[sum] = 1;
                //cout << i << " " << j << " " << sum << "\n";
            }
            int ans = -1;
            for(int j = 0; j < (1 << i); j += 1) if(not v[(1 << i) - 1 - j]){
                ans = j;
                break;
            }
            if(ans != -1){
                ok = 1;
                cout << "YES\n";
                for(int j = 0; j < k - i; j += 1) cout << 0;
                for(int j = 0; j < i; j += 1) cout << ((ans >> (i - j - 1)) & 1);
                cout << "\n";
            }
        }
        if(not ok) cout << "NO\n";
    }
    return 0;
}