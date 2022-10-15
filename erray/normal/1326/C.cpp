#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define all(v) v.begin(),v.end()
#define st first
#define nd second
#define ln '\n'
#define MAX 1000000009
#define MOD 998244353
#define N 100005
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pii;
typedef vector<int> vi;
int n, k, x;   
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    vi v;
    ll ans1 = 0, ans2 = 1;
    for(int i = 0; i < n; i++){
    	cin >> x;
    	if(x > n - k){
    		ans1 += x;
    		v.pb(i);	
    	}
    }
    for(int i = 0; i < v.size() - 1; i++){
    	ans2 = (ans2 * (v[i + 1] - v[i])) % MOD;
    }
    cout << ans1 << " " << ans2;

}