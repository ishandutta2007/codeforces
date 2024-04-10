#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 998244353;

int n;
ll a[200010];

void solve() {
    cin >> n;
    ll sum = 0;
    for(int i=0; i<n; i++) cin >> a[i], sum += a[i];
    sort(a, a+n);

    priority_queue<ll> pq;
    pq.em(sum);

    while(pq.size() <= n && pq.size() && pq.top() > 2) {
        ll x = pq.top();
        pq.pop();

        if(a[n-1] == x) n--;
        else {
            pq.em(x-x/2);
            pq.em(x/2);
        }
    }

    if(pq.size() > n) {
        cout << "NO\n";
        return;
    }

    while(pq.size() < n) {
        ll x = pq.top();
        pq.pop();
        pq.em(x-x/2);
        pq.em(x/2);
    }

    while(pq.size()) {
        ll x = pq.top();
        pq.pop();

        if(a[n-1] == x) n--;
        else {
            cout<<"NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}