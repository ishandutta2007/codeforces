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

const int maxn = 500005, maxa = 10000005;
ll d[maxa], r[maxn][2];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 2; i < maxa; i++)
        if (d[i] == 0)
            for (int j = i; j < maxa; j += i)
                d[j] = i;
    for (int i = 0; i < n; i++) {
        int a, b = 1; cin >> a;
        r[i][0] = r[i][1] = -1;
        for (int p = d[a]; a%p == 0; a /= p)
            b *= p;
        if (a > 1) {
            r[i][0] = a;
            r[i][1] = b;
        }
    }
    for (int i = 0; i < n; i++)
        cout << r[i][0] << " \n"[i==n-1];
    for (int i = 0; i < n; i++)
        cout << r[i][1] << " \n"[i==n-1];
}