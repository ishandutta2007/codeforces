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
const ll sz = 333;

int ans;
int n;
ll a[100010];

int main() {
    fast;

    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];

    for(int i=-sz; i<=sz; i++) {
        vector<ll> v;
        for(int j=1; j<=n; j++) v.eb(a[j] + j * i);
        sort(all(v));
        for(int j=0, k; j<v.size(); ) {
            k = j;
            while(k < v.size() && v[k] == v[j]) k++;
            ans = max(ans, k - j);
            j = k;
        }
    }

    for(int i=1; i<=n; i++) {
        vector<ll> v;
        for(int j = i+1; j<i+sz && j <= n; j++) {
            if((a[j] - a[i]) % (j - i) == 0) v.eb((a[j] - a[i]) / (j - i));
        }

        sort(all(v));
        for(int j=0, k; j<v.size(); ) {
            k = j;
            while(k < v.size() && v[k] == v[j]) k++;
            ans = max(ans, k - j + 1);
            j = k;
        }
    }

    cout << n - ans;
}