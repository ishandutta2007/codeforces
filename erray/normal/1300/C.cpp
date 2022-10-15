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
ll arr[N][50]; 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    vector <ll> v; 
    for(int i = 0; i < t;i++){
        cin >> n;
        v.pb(n);
        for(int q = 0; q < 40; q++){
            arr[i][q] = n % 2;
            n/=2;
        }
    }
    ll ans;
    for(int i = 40; i >= 0; i--){
        ll ct = 0, nod = 0;
        for(int q = 0; q < t;q++){
            if(arr[q][i]){
                ct++;
                nod = q;
            }
        }
        if (ct == 1){
            swap(v[nod], v[0]);
             for(auto a : v){
                cout << a << " ";
            }
            return 0;
        }
    }
     for(auto a : v){
        cout << a << " ";
    }
   
    return 0;

}