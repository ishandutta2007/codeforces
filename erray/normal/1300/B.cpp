#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define umap unordered_map
#define flush fflush(stdout) 
#define st first
#define nd second 
#define pb push_back
#define mp make_pair
#define ln "\n"
#define all(v) v.begin(),v.end()
#define MAX 1000000009
#define MOD 1000000007
#define mid (start + end) / 2 
#define R(ii) (ii + ii + 1)
#define L(ii) (ii + ii)
#define N 100005
using namespace std;
ll n, t,  x, k, m;
vector <ll> v;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--){
        v.clear();
        cin >> n;
        ll tmp = n * 2;
        while (tmp--){
            cin >> x;
            v.pb(x);
        }
        sort(all(v));
        cout << v[n] - v[n - 1] << ln;
    }
    return 0;

}