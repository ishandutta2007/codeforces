#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define all(v) v.begin(),v.end()
#define st first
#define nd second
#define L (no<<1)
#define R L|1
#define mid (s + e)>>1
#define ln '\n'
#define MAX (1<<31)
#define MOD 998244353
#define N 300005
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pii;
typedef vector<int> vi;
ll n, pw[N];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    pw[0] = 1;
    for(ll i = 1; i <= n; i++)/*cout << */(pw[i] = (pw[i - 1] * 10)%MOD)/* << ln*/;
    for(ll i = n; i>= 2; i--){
        cout <<(ll)(pw[i - 2]*81*(i-2)+pw[i - 1]*18)%MOD<< " "; 
    }
    cout << 10;
}