#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

int n;
ll c[222][222];
ll dp[222][222];
ll p[222][222];
int ans[222];

ll cost(int i, int j) {
    return c[j][n] - c[i-1][n] - (c[j][j] + c[i-1][i-1] - 2 * c[i-1][j]);
}

void f(int l, int r, int par = 0) {
    if(l > r) return;
    int m = p[l][r];
    ans[m] = par;
    f(l, m-1, m);
    f(m+1, r, m);
}

int main() {
    fast;

    cin >> n;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> c[i][j];

            c[i][j] += c[i][j-1] + c[i-1][j] - c[i-1][j-1];
        }
    }

    for(int d=0; d<n; d++) {
        for(int i=1; i+d<=n; i++) {
            int j = i + d;
            dp[i][j] = INF;
            for(int k=i; k<=j; k++) {
                if(dp[i][k-1] + dp[k+1][j] + cost(i, k-1) + cost(k+1, j) < dp[i][j]) {
                    dp[i][j] = dp[i][k-1] + dp[k+1][j] + cost(i, k-1) + cost(k+1, j);
                    p[i][j] = k;
                } 
            }
        }
    }

    f(1, n);

    for(int i=1; i<=n; i++) cout << ans[i] << " ";
}