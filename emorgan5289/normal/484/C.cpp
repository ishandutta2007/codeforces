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

const int N = 1e6+6;
int p[N], a[N], b[N];
deque<char> q;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, t; cin >> s; t = s;
    int n = s.size();
    int m; cin >> m;
    while (m--) {
        int k, d; cin >> k >> d;
        int x = k-1;
        for (int i = 0; i < d; i++)
            for (int j = i; j < k; j += d)
                p[j] = (x++)%k;

        x = p[0]; do {
            q.push_front(s[x]), x = p[x];
        } while (x != p[0]);
        for (int i = 0; i < n-k; i++) {
            t[i] = q.front(); q.pop_front();
            q.pb(s[i+k]);
        }

        iota(a, a+k, 0);
        for (int y = 1; y <= n-k+1; y <<= 1) {
            if ((n-k+1)&y) {
                for (int i = 0; i < k; i++)
                    b[i] = p[a[i]];
                copy(b, b+k, a);
            }
            for (int i = 0; i < k; i++)
                b[i] = p[p[i]];
            copy(b, b+k, p);
        }
        for (int i = 0; i < k; i++)
            t[n-k+((a[i]+1)%k)] = s[i];
        x = k-1;
        q.pb(q.front()), q.pop_front();
        for (int i = 0; i < d; i++)
            for (int j = i; j < k; j += d)
                p[j] = (x++)%k;
        x = p[0]; do {
            t[((x+1)%k)+n-k] = q.back(), q.pop_back();
            x = p[x];
        } while (x != p[0]);
        cout << t << "\n";
        s = t;
    }
}