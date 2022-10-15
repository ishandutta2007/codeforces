
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
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--){
    	cin >> n;
    	vector <pp> v; 
    	while(n--){
    		cin >> a >> b;
    		v.pb(mp(a, b));
    	} 	
        sort(all(v));
    	ll mn = -1, sn = -1, ct  = -1, nxt = 0, best = -1, sum = 0; 
        for(int i = 0; i < v.size(); i++){
            nxt = 0;
            ll start  = v[i].st, end = v[i].nd; 
            if(mn == -1 || v[mn].nd < start){
                sum++;
                nxt = -1;
            }
            else if(sn == -1 || v[sn].nd < start){
                ct++;
            }
            ll old = 0;
            if(mn == -1 || v[mn].nd < end){
                best = max(ct, best);
                ct = nxt;
                sn = mn;
                mn = i;
            }
            else if(sn == -1 || v[sn].nd < v[i].nd){
                sn = i;
            }
            //cout << mn << " " << sn <<  << " " << ct << ln;

        }
         best = max(ct, best);
        cout << sum + best << ln;
    }
    
    return 0;
}