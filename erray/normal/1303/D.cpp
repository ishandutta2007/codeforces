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
ll n, t, x, a, b, c;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    //cout << "test" << ln;

    while (t-- ){
        cin >> n >> b;
        multiset <ll, greater <ll> > ms;
        ll sum = 0;
        while (b--){
            //cout << b << " ";
            cin >> x;
            sum += x;
            ms.insert(x);
        }

        if (sum < n){
            cout << -1 << ln;
            continue;
        }

        ll ans = 0;
        while (n && !ms.empty()){
            //cout << n<< ln;
            ll val = *ms.begin();
            ms.erase(ms.begin());
            if (val <= n){
                n -= val;
                sum -= val;
            }
            else if (sum - val >= n){
                sum -= val;

            }
            else {
                if (val != 1){
                    ms.insert(val / 2);
                    ms.insert(val / 2);
                    ans++;
                }
            }
        }
        cout << ans << ln;
    }

    return 0;
}