#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;
using pi = pair<int,int>;

#define ST first
#define ND second
#define PB push_back

const int nax = 300 * 1000 + 10;
int t,n,k;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k >> s;
        bool ans = 1;
        for(int i = 0; i < k; ++i) {
            bool zero = 0, one = 0;
            for(int j = i; j < n; j += k) {
                if(s[j] == '1') one = 1;
                if(s[j] == '0') zero = 1;
            }
            if(zero && one) ans = 0;
            if(!zero && !one) continue;
            for(int j = i; j < n; j += k) {
                if(one) s[j] = '1';
                else if(zero) s[j] = '0';
            }
        }
        int cnt0 = 0, cnt1 = 0;
        for(int i = 0; i < k; ++i) {
            if(s[i] == '1') cnt1++;
            if(s[i] == '0') cnt0++;
        }
        if(cnt1 > k/2 || cnt0 > k/2) ans = 0;
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }

}