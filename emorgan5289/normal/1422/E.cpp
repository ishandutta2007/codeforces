#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 1e5+5;
vector<pair<int, string>> ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    string stk = "$", dst = "$";
    vector<int> ind;
    reverse(all(s));
    int i = 0;
    for (auto& x : s) {
        if (x == stk.back()
            && (x > stk[stk.size()-2] || x == stk[stk.size()-2] && x > dst[dst.size()-2])
            && ind.back() == i-1) {
            stk.pop_back(), ind.pop_back();
            if (stk.back() != x && dst.back() == x) dst.pop_back();
        } else {
            stk.pb(x), ind.pb(i);
            if (dst.back() != x) dst.pb(x);
        }
        i++;
        if (stk.size() <= 11)
            ans.pb({stk.size()-1, stk.substr(1, 10)});
        else
            ans.pb({stk.size()-1, stk.substr(1, 2)+"..."+stk.substr(stk.size()-5, 5)});
    }
    reverse(all(ans));
    for (auto& [i, x] : ans) {
        reverse(all(x));
        cout << i << " " << x << "\n";
    }
}