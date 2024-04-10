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

const int N = 1e6+5;
int v[N], r[N], p[N];
vector<int> a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    if (n%2 == 0) {
        cout << "First" << endl;
        for (int i = 0; i < 2*n; i++)
            cout << i%n+1 << " ";
        cout << endl;
    } else {
        cout << "Second" << endl;
        for (int i = 0; i < 2*n; i++) {
            int x; cin >> x; a[x-1].pb(i);
        }
        for (int i = 0; i < n; i++) {
            p[a[i][0]] = a[i][1];
            p[a[i][1]] = a[i][0];
        }
        int c = 0;
        for (int i = 0; i < 2*n; i++)
            for (int j = i; !v[j]; j = p[(j+n)%(2*n)]) {
                r[j] = v[j] = v[(j+n)%(2*n)] = 1;
                c = (c+j+1)%2*n;
            }
        for (int i = 0; i < 2*n; i++)
            if ((c == 0) == r[i])
                cout << i+1 << " ";
        cout << endl;
    }
    int x; cin >> x;
}