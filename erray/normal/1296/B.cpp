#include <bits/stdc++.h>
typedef long long  ll;
typedef unsigned long long int ull;
#define st first 
#define nd second 
#define pb push_back
#define mp make_pair 
#define MAX 1000000009
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define IT iterator 
#define ln "\n"
#define mid (start + end)/2
#define R(ii) (ii * 2) + 1
#define L(ii) (ii * 2)
#define pp pair<ll,ll> 
#define vi vector<ll> 
#define all(vv) vv.begin(),vv.end()
#define N 1000005
using namespace std;       
ll t, n;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--){
        cin >> n;
        ll ans = 0;
        while (n > 9){
           // cout << n << ln;
            ll a = n / 10;
            ans += (a * 10);
            n = (n % 10) + a;
        }
        cout << ans + n << ln;
    }
    return 0;
}