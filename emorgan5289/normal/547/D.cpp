#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 200005;
int x[N], y[N], r[N];
set<int> h[N], v[N];

void vis(int i) {
    h[x[i]].erase(h[x[i]].find(i));
    v[y[i]].erase(v[y[i]].find(i));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        h[x[i]].insert(i);
        v[y[i]].insert(i);
    }
    for (int i = 0; i < n; i++) {
        if (h[x[i]].find(i) == h[x[i]].end()) continue;
        int j = i; r[j] = 0; vis(j);
        while (1) {
            int k;
            if (r[j]) {
                if (h[x[j]].empty()) break;
                k = *h[x[j]].begin();
            } else {
                if (v[y[j]].empty()) break;
                k = *v[y[j]].begin();
            }
            r[k] = r[j]^1; j = k; vis(k);
        }
        j = i;
        while (1) {
            int k;
            if (r[j]) {
                if (v[y[j]].empty()) break;
                k = *v[y[j]].begin();
            } else {
                if (h[x[j]].empty()) break;
                k = *h[x[j]].begin();
            }
            r[k] = r[j]^1; j = k; vis(k);
        }
    }
    for (int i = 0; i < n; i++)
        cout << "br"[r[i]];
    cout << "\n";
}