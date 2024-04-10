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
int t, n, x;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    cin >> t;
    while(t--){
        cin >> n;
        vector <int> v[2];
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < n; j++){
                cin >> x;
                v[i].pb(x);
            }
        }
        sort(all(v[1]));
        sort(all(v[0]));
        for(int i = 0; i < n; i++){
            cout << v[0][i] << " ";
        }
        cout << ln;
        for(int i = 0; i < n; i++){
            cout << v[1][i] << " ";
        }
        cout << ln;
    }
    return 0;
}