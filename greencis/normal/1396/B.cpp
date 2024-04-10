#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;

int a[105];

bool solve(vector<int> v) {
    int s = 0;
    for (int x : v)
        s ^= x;
    if (s == 0)
        return false;
    priority_queue<int> q;
    for (int x : v)
        if (x > 0)
            q.push(x);
    while (q.size() >= 2) {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        --a; --b;
        if (a > 0) q.push(a);
        if (b > 0) q.push(b);
    }
    return q.size() == 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int& x : v)
            cin >> x;
        cout << (solve(v) ? "T" : "HL") << endl;
    }
}