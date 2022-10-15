#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define umap unordered_map
#define all(v) v.begin(),v.end()
#define ln '\n'
#define MOD 1000000007
#define N 200005
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
int t, n, x, m;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    cin >> t;
    while(t--){
        cin >> n >> s;
        int ans;
        string best = "*";
        for(int i = 0; i < n; i++){
            string mine = "", r = "";
            for(int j = 0; j < n; j++){
                if(j < i ){
                    r+= s[j];
                }
                else mine += s[j];
            }
            if((n - i) % 2 == 1)reverse(all(r));
            mine += r;
            if(best == "*" || best > mine){
                best = mine;
                ans = i + 1;
            }
        }


        cout << best << ln << ans<< ln;
    }
    return 0;
}