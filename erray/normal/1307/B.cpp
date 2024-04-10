#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define umap unordered_map
#define flush fflush(stdout)
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ln "\n"
#define all(v) v.begin(),v.end()
#define MAX 1000000009
#define MOD 1000000007
#define mid (start + end) / 2
#define R(ii) (ii + ii + 1)
#define L(ii) (ii + ii)
#define N 100005
using namespace std;
typedef pair<ll,ll> pp;
typedef vector<ll> vi;
ll n, q, k, t, x, y, a, b, c;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--){
        cin >> n >> k;
        ll ans = MAX;
        while(n--){
            cin >> x;
            if(x > k) ans = min(ans, (ll)2);
            else ans = min(ans, (ll)ceil((double)k / x));
        }
        cout << ans << ln;
    }
    return 0;
}