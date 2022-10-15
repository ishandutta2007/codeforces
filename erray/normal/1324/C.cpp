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
#define N 3005
using namespace std;
typedef long long ll;
typedef pair<int ,int > pii;
int t;
string s;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> s;
        vector <int> v;
        int ans = -1; 
        v.pb(-1);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'R'){    
                v.pb(i);
            }
        }
        v.pb(s.size());
        for(int i = 0; i < v.size() - 1; i++){
            ans = max(ans, v[i + 1] - v[i]);
        }
        cout << ans << ln;
    }

}