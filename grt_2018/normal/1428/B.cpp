#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;
using pi = pair<int,int>;

#define ST first
#define ND second
#define PB push_back

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        bool eL = 0, eR = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '<') eL = 1;
            if(s[i] == '>') eR = 1;
        }
        if((!eL && !eR) || (eL != eR)) {
            cout << n << "\n";
            continue;
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int b = (i - 1 + n) % n;
            if(s[i] == '-' || s[b] == '-') {
                ans++;
            }
        }
        cout << ans << "\n";
    }


}