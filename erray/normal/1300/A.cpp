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
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--){
        cin >> n;
        ll sum = 0, ct = 0;
        vector <ll> v; 
        while (n--){
            cin >> x;
            sum += x;
            if (x == 0){
                ct++;
            }
        }
        sum += ct;
        if (sum == 0){
            cout << ct + 1;
        }
        else {
            cout << ct;
        }
      cout << ln;
    }   
    return 0;

}