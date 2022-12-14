#include <bits/stdc++.h>
using namespace std;

void ioThings() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
}

using ll = long long;
#define debug(x) cerr << #x << ": <" << x << ">\n"
#define sz(x) (int)x.size()
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int main() {
    ioThings();

    int n; cin >> n;
    int cards[n];
    for (int i = 0; i < n; i++)
        cin >> cards[i];
    
    int s = 0, d = 0, i = 0, turn = 0;
    while (i < n) {
        int p;
        if (cards[i] > cards[n - 1])
            p = cards[i++];
        else
            p = cards[n-- - 1];
        if (turn)
            d += p;
        else
            s += p;
        turn ^= 1;
    }

    cout << s << ' ' << d;

    return 0;
}