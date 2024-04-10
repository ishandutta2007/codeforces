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
ll n, a, b, k, x, ans = 0;
vector <ll> v; 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> a >> b >> k;
    ll sum = a + b;
    vector <ll> v;  
    while (n--){
        cin >> x;
        x %= sum;
        if (x == 0){
            x = sum;
        }
        x -= a;
         v.pb(ceil((double) x / a));
    }
    sort(all(v));
    for(int i = 0; i  < v.size(); i++){
        if (k >= v[i]){
            ans++;
            k -= v[i];
        }
    }
    cout << ans;
    return 0;
}