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
ll n, q,  t, x, a, b, c, y, now, ti;
string s;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--){
        cin >> n >> s;
        ll lft = n;
        for(int i = 0; i < n; i++){
            ll pn = 0;
            while (s[i] == '<'){
                pn++;
                i++;
            }
            for(int i = lft - pn; i <= lft; i++){
                cout << i << " ";
            }
            lft -= pn + 1;
        }
        cout << ln;
        lft = 1;
        for(int i = 0; i < n; i++){
            ll pn = 0;
            while (s[i] == '>'){
                pn++;
                i++;
            }
            for(int i = lft + pn; i >= lft; i--){
                cout << i << " ";
            }
            lft += pn + 1;
        }
        cout << ln;
    }
    return 0;
}