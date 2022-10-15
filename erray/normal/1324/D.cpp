#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define flush fflush(stdout)
#define all(v) v.begin(),v.end()
#define st first
#define nd second
#define ln '\n'
#define MAX 1000000009
#define MOD 1000000007
#define N 500005
using namespace std;
typedef long long ll;
typedef pair<int ,int > pii;
int t, x, a[N], b[N];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    vector <int> v; 
    for(int i = 0; i < t; i++){
        cin >> a[i];
    }
    for(int i = 0; i < t; i++){
        cin >> b[i];
        b[i] = a[i] - b[i];
        v.pb(b[i]);
    }
    sort(all(v));
    ll ans = 0;
    for(int i = 0; i < t; i++){
        auto a = lower_bound(all(v), -b[i] + 1);
        ans += v.size() - (a - v.begin());
        if(b[i] > 0)ans--;
        //cout << v.size() - (a - v.begin()) << ln;
    }
    //cout << ans << ln;
    cout << ans / 2;

}