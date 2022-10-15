#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define umap unordered_map
#define all(v) v.begin(),v.end()
#define ln '\n'
#define MOD 1000000007
#define N 1005
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
int n, m, t;
ll ans = 1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    cin >> t >> m;
    vector <int> v;
    while(t--){
        cin >> n;
        v.pb(n);
    }
    if(v.size() > m){
        cout << 0;
        return 0;
    }
    for(int i = 0; i < v.size(); i++){
        for(int j = i + 1; j < v.size(); j++){
            ans = (ans * abs(v[i] - v[j]))%m;
        }
    }
    cout << ans;


}