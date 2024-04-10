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

const int maxn = 4005;
const ll mod = 1e9+7;
ll b[maxn], c[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
    }
    b[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            b[i] = (b[i]+c[i-1][j]*b[j])%mod;
    ll out = 0;
    for (int i = 0; i < n; i++)
        out = (out+c[n][i]*b[i])%mod;
    cout << out << "\n";
}