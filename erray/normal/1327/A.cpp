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
ll n , x, t;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n >> x;
        n -= x * x;
        if(n < 0){
            cout << "NO" << ln;
            continue;
        } 
        n += x * x;
        if((x % 2) == (n % 2)){
            cout << "YES" << ln;
        }
        else {
            cout << "NO" << ln;
        }
    }
}