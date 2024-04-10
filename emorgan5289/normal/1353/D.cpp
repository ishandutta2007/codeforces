#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 200005;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a[maxn] = {};
        set<array<int, 3>> s;
        s.insert({-n, 0, n-1});
        int i = 0;
        while (!s.empty()) {
            int x, y;
            debug(s);
            auto it = s.begin();
            x = (*it)[1], y = (*it)[2];
            s.erase(*it);
            int m = (x+y)/2;
            a[m] = ++i;
            if (m > x)
                s.insert({x-m, x, m-1});
            if (m < y)
                s.insert({m-y, m+1, y});
        }
        for (int j = 0; j < n; j++)
            cout << a[j] << " \n"[j==n-1];
    }
}