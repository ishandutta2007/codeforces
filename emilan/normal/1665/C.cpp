#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> freq(n);
    for (int u = 1; u < n; u++) {
        int p;
        cin >> p;
        freq[p - 1]++;
    }

    freq.erase(remove(ALL(freq), 0), end(freq));
    sort(ALL(freq));

    for (int i = 0; i < SZ(freq); i++) {
        freq[i] -= i + 2;
    }

    priority_queue pq(ALL(freq));

    int t = 0;
    while (pq.top() > t) {
        int x = pq.top();
        pq.pop();

        pq.push(x - 1);
        t++;
    }

    cout << SZ(freq) + 1 + t << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}