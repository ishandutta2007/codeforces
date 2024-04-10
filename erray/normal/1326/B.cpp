#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define all(v) v.begin(),v.end()
#define st first
#define nd second
#define ln '\n'
#define MAX 1000000009
#define MOD 1000000007
#define N 100005
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pii;
typedef vector<int> vi;
int t, n;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
 	cin >> t;
 	vi v, ans;
 	int p = 0;
 	while(t--){
 		cin >> n;
 		v.pb(n);
 	}
 	int mx = 0;
 	for(auto a : v){
 		cout << mx + a << " ";
 		mx = max(mx, a + mx);
 	}
}