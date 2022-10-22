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

int n, q;
int a[100010];
int cnt[2];

int main() {
    fast;

    cin >> n >> q;

    for(int i=1; i<=n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    while(q--) {
        int t, x;
        cin >> t >> x;

        if(t == 1) {
            cnt[a[x]]--;
            a[x] = 1 - a[x];
            cnt[a[x]]++;
        }
        else {
            if(cnt[1] >= x) cout << "1\n";
            else cout << "0\n";
        }
    }
}