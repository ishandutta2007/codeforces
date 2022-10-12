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

const int maxn = (1<<21) + 5;
int a[maxn], f[maxn][2];

void upd(int i, int x) {
    if (x > f[i][0]) {
        f[i][1] = f[i][0]; f[i][0] = x;
    } else if (x > f[i][1])
        f[i][1] = x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < maxn; i++)
        f[i][0] = f[i][1] = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; upd(a[i], i);
    }
    for (int i = 0; i < 21; i++)
        for (int j = 0; j < 1<<21; j++)
            if ((~j)&(1<<i)) {
                upd(j, f[j^(1<<i)][0]);
                upd(j, f[j^(1<<i)][1]);
            }
    int r = 0;
    for (int i = 0; i < n-2; i++) {
        int x = 0;
        for (int j = 20; j >= 0; j--)
            if (((~a[i])&(1<<j)) && f[x|(1<<j)][0] > i && f[x|(1<<j)][1] > i)
                x |= (1<<j);
        r = max(r, a[i]|x);
    }
    cout << r << "\n";
}