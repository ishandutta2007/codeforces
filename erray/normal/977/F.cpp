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
#define N 200005
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pii;
int n, x, dp[N];
map <int, int> m;  
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    vector <int> v;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.pb(x);
    }  
    
    for(int i = v.size() - 1; i >= 0; i--){
        m[v[i]] = i;
        dp[i] = 1 +  dp[m[v[i] + 1]];
      //  cout << dp[i] << ln;
    }
    
    int mx = 0, nod;
    for(int i = 0; i < v.size(); i++){
        mx = max(dp[i], mx);
    }
    for(int i = 0; i< v.size(); i++ ){
        if(dp[i] == mx){
            nod = i;
            break;
        }
    }
    int num = v[nod] + 1;
    cout << mx << ln << nod + 1 << " ";
    for(int i  = nod; i < v.size(); i++){
        if(v[i] == num){
            num++;
            cout << i + 1 << " ";
        }
    }
    
}