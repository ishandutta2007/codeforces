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

const int maxn = 200005;
int a[maxn], b[maxn][2];
bool v[maxn], c[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b[i][0] >> b[i][1];
        b[i][0]--, b[i][1]--;
        a[b[i][0]] = b[i][1];
        a[b[i][1]] = b[i][0];
    }
    for (int i = 0; i < 2*n; i++) {
        if (v[i]) continue;
        int j = i;
        do {
            c[j] = 0; c[j^1] = 1;
            v[j] = v[j^1] = 1;
            j = a[j^1];
        } while (j != i);
    }
    for (int i = 0; i < n; i++) {
        cout << (c[b[i][0]] ? 1 : 2) << " ";
        cout << (c[b[i][1]] ? 1 : 2) << "\n";
    }
}