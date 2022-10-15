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
int n, k, x, t;
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
        cin >> n;
        umap <int, vector <int> > pl;
        bool b = 0; 
        for(int i = 0; i < n; i++){
            cin >> x;
            pl[x].pb(i);
            if(pl[x][pl[x].size() - 1] - pl[x][0] > 1){
                b = 1;
            }
        }
        cout << (b ? "YES" : "NO") << ln;
    }

}