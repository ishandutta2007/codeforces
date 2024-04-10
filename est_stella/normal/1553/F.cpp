#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define pre(x) cout<<fixed; cout.precision(x);

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

int n, sz = 600;
ll a[200010];
ll ans[200010];
ll s, cnt;
ll num[666];
ll dp[666][666];

struct BIT {
    ll tree[600010];

    BIT() {
        memset(tree, 0, sizeof(tree));
    }

    void update(int i, int x) {
        while(i <= 600000) {
            tree[i] += x;
            i += i & -i; 
        }
    }

    ll sum(int i) {
        ll ret = 0;
        while(i) {
            ret += tree[i];
            i -= i & -i;
        }
        return ret;
    }
} t1, t2;

int main() {
    fast;

    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> a[i];

        if(a[i] > sz) {
            ans[i] += t1.sum(a[i]) + cnt * a[i];
            ans[i] += s;

            for(int j=a[i]; j <= 300000; j += a[i]) {
                t1.update(j, -a[i]);
                ans[i] -= (j / a[i]) * (t2.sum(j + a[i] - 1) - t2.sum(j-1)) * a[i];
            }
            cnt++;

            for(int j=2; j<=sz; j++) {
                ans[i] += num[j] * (a[i] % j);
            }
        }
        else {
            for(int j=1; j<a[i]; j++) {
                ans[i] += j * dp[a[i]][j];
            }

            for(int j=2; j<a[i]; j++) {
                ans[i] += num[j] * (a[i] % j);
            }

            ans[i] += (i - t2.sum(a[i]) - 1) * a[i];

            num[a[i]]++;
        }

        s += a[i];
        t2.update(a[i], 1);

        for(int j=2; j<=sz; j++) {
            dp[j][a[i]%j]++;
        }

    }

    for(int i=1; i<=n; i++) {
        ans[i] += ans[i-1];
        cout << ans[i] << " ";
    }
}