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
#define N 500005
using namespace std;
typedef long long ll;
typedef pair<int ,int > pii;
int t, n, x;
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
        cout << (n % x == 0 ? "YES" : "NO") << ln;
    }
    
}