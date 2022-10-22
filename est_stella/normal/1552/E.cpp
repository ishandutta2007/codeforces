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
const ll Mod = 998244353;

int n, k;
vector<int> pos[111];
int num[10010];
int ans[10010][2];
int a[10010];

int main() {
    fast;

    cin >> n >> k;

    for(int i=1; i<=n*k; i++) {
        cin >> a[i];
        num[i] = pos[a[i]].size();
        pos[a[i]].eb(i);
    }

    int e = 0;
    int cnt = 0;

    for(int i=1; i <= n; i+=(k-1)) {
        int e = 0;
        for(int j=1; j<=n*k; j++) {
            if(a[j] < i || a[j] >= i + k-1) continue;

            int c = a[j];
            if(ans[c][0]) continue;
            if(num[j] > 0 && e < pos[c][num[j]-1]) {
                e = j;
                ans[c][0] = pos[c][num[j]-1];
                ans[c][1] = j;
            }
        }   
    }

    for(int i=1; i<=n; i++) cout << ans[i][0] << " " << ans[i][1] << "\n";
}