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
ll n, t, x, a, b, k, m, c ,y;
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
        cin >> a >> b >> x >> y;
        ++x;
        ++y;
        
        ll yat = max(a - x,  x - 1);
        ll dik = max(b - y, y - 1);
        cout << max(yat * b, dik * a) << ln;
    }

    return 0;
}