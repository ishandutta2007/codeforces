#include <bits/stdc++.h>
                  
using namespace std;
          
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n, k;
int a[1007];
int b[1007];
vector<int> g[1007];
bool was[1007];

void dfs(int v){
    was[v] = 1;
    if (v == k) cout << "YES", exit(0);
    for (int to : g[v]) if (!was[to]) dfs(to);
}   

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    k--;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int last = -1;
    for (int i = 0; i < n; i++){
        if (a[i]){
            if (last != -1){
                g[last].pb(i);
            }
            last = i;
        }
    }
    last = -1;
    for (int i = n - 1; i >= 0; i--){
        if (b[i]){
            if (last != -1){
                g[last].pb(i);
            }
            last = i;
        }
    }

    dfs(0);
    cout << "NO";
}