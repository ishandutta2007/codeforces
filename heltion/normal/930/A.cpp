#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define maxn 120000
vector<int> G[maxn];
int d[maxn];
void DFS(int u, int dep){
    d[dep] ^= 1;
    for(int v : G[u]) DFS(v, dep + 1);
}
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 2; i <= n; i += 1){
        int p;
        cin >> p;
        G[p].push_back(i);
    }
    DFS(1, 1);
    int ans = 0;
    for(int i = 1; i <= n; i += 1) ans += d[i];
    cout << ans;
}