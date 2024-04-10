#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const ll INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

int cnt7, cnt5, cnt3, cnt2;

int get_pow(int n, int p) {
    if (n == 0) {
        return 0;
    }
    int ans = n / p;
    return ans + get_pow(n/p, p);
}
int main() {
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.pb(s[i] - '0');
    }
    for (int i = 0; i < n; i++) if (v[i] > 1) {
        cnt7+=get_pow(v[i], 7);
        cnt5+=get_pow(v[i], 5);
        cnt3+=get_pow(v[i], 3);
        cnt2+=get_pow(v[i], 2);
    }
    vector<int> ans;
    while (cnt7) {
        ans.pb(7);
        cnt7--;
        cnt5--;
        cnt3-=2;
        cnt2-=4;
    }
    while (cnt5) {
        ans.pb(5);
        cnt5--;
        cnt3-=1;
        cnt2-=3;
    }
    while (cnt3) {
        ans.pb(3);
        cnt3-=1;
        cnt2-=1;
    }
    while (cnt2) {
        ans.pb(2);
        cnt2-=1;
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    return 0;
}