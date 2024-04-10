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
typedef pair<pp,pp> pp4; 
typedef vector<ll> vi; 
ll n, t, x, a, b, k, m, c;
vi v;
ll ans[N];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("outt.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    ll mn = MAX;
    vector <pp> tmp; 
    for(int i = 0; i < t; i++){
        cin >> x;
        tmp.pb(mp(x, i));
        mn = min(x, mn);
        v.pb(x);
    }
    vi old = v;
    sort(all(tmp));
    vi r = v;
    ll mx = -1;
    for(int j = 0; j < t; j++){
        v = old;
        ll pos = tmp[j].nd;
        ll lft = tmp[j].st, right = tmp[j].st;
        for(int i = 1; i <= t; i++){
             if(pos + i < t){
                ll tmp2 = pos + i;
                right=  min(right, v[tmp2]);
                v[tmp2] = right;
              }
            if(pos - i >= 0){
                ll tmp2 = pos - i;
                lft=  min(lft, v[tmp2]);
                v[tmp2] = lft;
            }
        }      
        ll ans = 0;
        for(auto a : v){
            ans += a;
        }
        if(ans > mx){
            mx = ans;
            r = v;
        }
    }

    for(auto a : r){
        cout << a << " ";
    }
    return 0;
}