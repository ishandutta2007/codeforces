#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

string s;
int x, y;
const ll INF = 1e18;

int main() {_
	cin >> s >> x >> y;
	bool one = 1;
	ll res = INF;
	for(int k = 0; k < 2; ++k) {
        int cnt1 = 0, cnt0 = 0;
        ll ans = 0;
        for(int i = (int)s.size() - 1; i >= 0; --i) {
            if(s[i] - '0' == one || s[i] == '?') {
                cnt1++;
                ans += (ll)cnt0 * y;
            } else {
                cnt0++;
                ans += (ll)cnt1 * x;
            }
        }
        res = min(res, ans);
        //cout << res << "\n";
        int c1 = 0, c0 = 0;
        for(int i = 0; i <= (int)s.size(); ++i) {
            if(s[i] - '0' == one) {
                cnt1--;
                c1++;
            } else if(s[i] != '?') {
                cnt0--;
                c0++;
            } else {
                cnt1--;
                ans -= (ll)cnt0 * y;
                ans -= (ll)c0 * x;
                c0++;
                ans += (ll)y * c1;
                ans += (ll)x * cnt1;
            }
            //cout << ans << "\n";
            res = min(res, ans);
        }
        one ^= 1;
        swap(x, y);
       //cout << "-----\n";
	}
	cout << res;
}