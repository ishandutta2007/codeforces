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
#define N 500005
using namespace std;
typedef pair<ll,ll> pp;
typedef vector<ll> vi; 
ll n, t, x, a, b, c, k, m;
umap <ll,ll> ct; 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    ll mat[n + 1][m + 1];
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		cin >> 	mat[i][j];
    	}
    }
    ll ans = n * m;
    for(int i = 1; i <= m; i++){
    	ll nec = i % m;
    	ct.clear();
    	vector <ll> S; 
    	for(int j = 1; j <= n; j++){
    		if(mat[j][i] % m == nec && ((ll)ceil((double) mat[j][i] / m)  - 1) < n) {
    			ll fark = ((j - 1 - (((ll)ceil((double) mat[j][i] / m)  - 1))) + n) % n;
    			//cout << fark << ln;
    			if(ct[fark] == 0){
    				S.pb(fark);
    			}
    			ct[fark]++;
    		}
    		//else cout << "pass" << ln;
    	}
    	ll best = -MAX;
    	for(auto a : S){
    		ll kay = abs(a);
    		ll say = ct[a];
    		best = max(say - kay, best);
    	}
    	if(best > 0){
    		ans -= best;
    	}
    }
    cout << ans;
    return 0;
	
}