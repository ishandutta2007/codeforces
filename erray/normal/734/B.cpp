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
ll a, b, c, d;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);  
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> a >> b >> c >> d;
    ll ct = min(a, c);
    ct = min(ct, d);
    a -= ct;
    ll ans = ct * 256;
    ans += min(a, b) * 32;
    cout << ans;
}