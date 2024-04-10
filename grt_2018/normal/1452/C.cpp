#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;
using pi = pair<int,int>;

#define ST first
#define ND second
#define PB push_back

int t, n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> s;
        n = (int)s.size();
        int cnt1 = 0, cnt2 = 0, ans = 0;
        for(auto x : s) {
            if(x == '(') cnt1++;
            if(x == '[') cnt2++;
            if(x == ')' && cnt1 > 0) {
                cnt1--;
                ans++;
            }
            if(x == ']' && cnt2 > 0) {
                cnt2--;
                ans++;
            }
        }
        cout << ans << "\n";
    }

}