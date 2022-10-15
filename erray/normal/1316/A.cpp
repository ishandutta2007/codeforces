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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    cin >> t;
    while(t--){
        cin >> n >> m;
        int sum = 0;
        while(n--){
            cin >> x;
            sum += x;
        }
        cout << min(sum, m) << ln;
    }
    return 0;
}