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
#define MOD 1000000007
#define N 300005
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pii;
typedef vector<int> vi;
ll n ,m, x, t, a, b, k;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m >> k;
    if(n + m == 2){
        cout << 0;
        return 0;
    }
    for(int i = 0; i < k; i++){
        cin >> a >> b;
    }
    for(int i = 0; i < k; i++){
        cin >> a >> b;
    }
    cout << (n + m - 2) + n * m << ln;
    for(int i = 0; i < n - 1; i++){
        cout << 'U';
    }
    for(int i = 0; i < m - 1; i++){
        cout << 'R';
    }
    for(int i = 0;  i< m; i++){
        for(int j = 0; j < n - 1; j++){
            cout <<(i % 2 ? 'U' : 'D');
        }
        cout << 'L';
    }
}