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
ll n, q,  t, x, a, b, c, y;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--){
        ll bas = 0;
        cin >> q;
        vector <ll> v;
        while (q--){
            cin >> x;
            v.pb(x);
        }
        vector <ll> nec;
        for(int i = 0; i < v.size();i++){
            if (v[i] == -1){
                if (i > 0 ){
                    if (v[i - 1] != -1){
                        nec.pb(v[i - 1]);
                    }

                }
                if (i < v.size() - 1){
                    if (v[i + 1] != -1){
                        nec.pb(v[i + 1]);
                    }
                }
            }
            else{
                if (i < v.size() - 1){
                    if (v[i + 1] != -1){
                        bas = max(bas, abs(v[i + 1] - v[i]));
                    }
                }
            }
        }
        sort(all(nec));
        if (nec.size() == 0){
            cout << 0 << " " << 0 << ln;
        }

        else if (nec.size() == 1){
            cout << bas << " " << nec[0] << ln;
        }
        else {
            ll ans = nec[nec.size() - 1] - nec[0];
            ans = (ans + 1) / 2;
            cout << max(ans, bas) << " " << nec[0] + ans << ln;
        }
    }
    return 0;
}