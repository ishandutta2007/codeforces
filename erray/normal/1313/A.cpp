
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define umap unordered_map
#define flush fflush(stdout)
#define For(ii,aa,bb) for(int ii = aa; ii < bb; ii++) 
#define st first
#define nd second 
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ln "\n"
#define all(v) v.begin(),v.end()
#define MAX 1000000009
#define MOD 1000000007
#define mid (start + end) / 2 
#define R(ii) (ii + ii + 1)
#define L(ii) (ii + ii)
#define N 505
using namespace std;
typedef pair<ll,ll> pp;
typedef pair<pp,pp> pp4; 
typedef vector<ll> vi; 
int n, t, x, a, b, k, m, c;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("outt.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        ll ans = 0;
        vector <ll> v;
        v.pb(a);v.pb(b);v.pb(c);
        sort(all(v));
        a = v[0];b = v[1]; c = v[2];
        for(int i = 0; i < 2; i++){
            for(int q = 0; q < 2; q++){
                for(int j  = 0; j < 2; j++){
                    if(i <= a && q <= b && j <= c){
                        ans++;
                        a -= i;
                        b -= q; 
                        c -= j;
                    }
                }
            }
        }
        cout << --ans << ln;
    }
    
    return 0;
}