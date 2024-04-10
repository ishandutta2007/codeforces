#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int n,m,a[100105];

bool check(ll t) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        v[i] = a[i];
    int guys = m;
    while (guys--) {
        ll curt = t;
        while (v.size() && !v.back()) v.pop_back();
        if (curt <= v.size()) return false;
        curt -= v.size();
        while (curt > 0) {
            while (v.size() && !v.back()) v.pop_back();
            if (!v.size()) return true;
            if (curt >= v.back()) curt -= v.back(), v.pop_back();
            else v.back() -= curt, curt = 0;
        }
    }
    while (v.size() && !v.back()) v.pop_back();
    return !v.size();
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    ll L = 1ll, R = 1e18;
    while (L < R) {
        ll mid = (L + R) / 2ll;
        if (check(mid)) R = mid;
        else L = mid + 1ll;
    }
    cout << L;

    return 0;
}