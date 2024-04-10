#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

/*
6
0 1 0 1 0 0

*/

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

//    vector<int> b(1, 0);
//    for(int i = 1; i < n - 1; i++) {
//        if(a[i] != a[i - 1]) {
//            b.back()++;
//        } else {
//            b.push_back(0);
//        }
//    }

    vector<pii> b(1, {0, 0});
    for(int i = 1; i < n; i++) {
        if(a[i] != a[i - 1]) {
            b.back().s++;
        } else {
            b.emplace_back(i, i);
        }
    }

    int ans = 0;
    vector<int> res = a;
    for(auto p : b) {
        int len = p.s - p.f - 1;
        ans = max(ans, (len + 1) / 2);
        if(len > 0) {
            if(len % 2 == 0) {
                for(int j = p.f; j <= (p.s + p.f) / 2; j++)
                    res[j] = a[p.f];
                for(int j = (p.s + p.f) / 2 + 1; j < p.s; j++)
                    res[j] = a[p.s];
            } else {
                for(int j = p.f; j < p.s; j++)
                    res[j] = a[p.f];
            }
        }
    }

    cout << ans << endl;
    for(auto x : res)
        cout << x << ' ';
//    for(auto p : b)
//        cout << p.f << ' ' << p.s << endl;
}