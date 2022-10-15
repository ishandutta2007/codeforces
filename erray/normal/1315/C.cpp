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
#define MOD 998244353
#define mid (start + end) / 2 
#define R(ii) (ii + ii + 1)
#define L(ii) (ii + ii)
#define N 20005
using namespace std;
typedef pair<ll,ll> pp;
typedef pair<pp,pp> pp4; 
typedef vector<ll> vi; 
ll n, t, x, a, b, k , c ,y, p;
string s;   
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("outt.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n;
        vector <ll> v; 
        ll on = n;
        v.pb(-1);
        map <ll, bool> m;  
        while(n--){
            cin >> x;
            m[x] = 1;
            v.pb(x);
        }
        n = on;
        set <ll> S;    
        for(int i = 1; i <= 2 * n; i++){
            if(!m[i]){
                S.insert(i);
            }
        }
        vector <ll> ans;
        bool flag = 1;
        for(int i = 1; i < v.size(); i++){
            auto a = upper_bound(all(S), v[i]);
            if(a == S.end()){
                flag = 0;
            }
            else {
                ans.pb(v[i]);
                ans.pb(*a);
                S.erase(a);
            }

        }
        if(!flag){
            cout << -1 << ln;
            continue;
        }
        for(int i = 1; i < n; i++){
            if(v[i] != min(ans[2 * i - 1], ans[2 * i - 2])){
                flag = 0;
            }
            
        }
        if(flag){
            for(auto a : ans){
                cout << a << " ";
            }
        }
        else {
            cout << -1;
        }
        cout << ln;
        
    }
    
    return 0;
}