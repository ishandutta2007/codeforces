#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define em emplaces
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

int n, m;
vector<int> a[100010];
ll cnt[100010];
ll c[100010];
ll ans;

int main() {
    fast;
    cin >> n >> m;

    vector<int> a[100010];

    for(int i=0; i<n; i++) {
        int x;
        for(int j=0; j<m; j++) {
            cin >> x;
            a[i].eb(x);
            c[x]++;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            ans += cnt[a[i][j]] * i;
            cnt[a[i][j]]++;
            ans -= (c[a[i][j]] - cnt[a[i][j]]) * i;
        }
    }

    memset(cnt, 0, sizeof(cnt));

    for(int j=0; j<m; j++) {
        for(int i=0; i<n; i++) {
            ans += cnt[a[i][j]] * j;
            cnt[a[i][j]]++;
            ans -= (c[a[i][j]] - cnt[a[i][j]]) * j;
        }
    }

    cout << ans;
}