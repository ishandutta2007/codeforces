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
#define N 100000
using namespace std;
ll n, t,  x, k, m;
string s;   
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--){
        cin >> s;
        bool f = 0;
        ll ct = 0;
        for(int i = 0; i <s.size(); i++) ct+=s[i] - '0';
        ll ct2 = 0;
        ll ans = 0;
        for(int i = 0; i < s.size(); i++){
            if (s[i] == '1'){
                f = 1;
                ct2++;
                if (ct2 == ct){
                    break;
                }
            }
            else if (f){
                ans ++;
            }
        }
        cout << ans << ln;
    }

    return 0;

}