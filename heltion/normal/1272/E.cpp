#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
int a[maxn], n;
int d[2][maxn];
vector<int> G[maxn];
void fuck(int t){
    queue<int> q;
    for(int i = 1; i <= n; i += 1){
        d[t][i] = (a[i] & 1) == t ? 0 : maxn;
        if(d[t][i] == 0) q.push(i);
    }
    while (not q.empty()){
        int u = q.front();
        q.pop();
        for(int v : G[u]) if(d[t][v] > d[t][u] + 1){
            d[t][v] = d[t][u] + 1;
            q.push(v);
        }
    }
    //for(int i = 1; i <= n; i += 1) cout << d[t][i] << " "; cout << "\n";
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i += 1){
        cin >> a[i];
        if(i - a[i] >= 1) G[i - a[i]].push_back(i);
        if(i + a[i] <= n) G[i + a[i]].push_back(i);
    }
    fuck(0);
    fuck(1);
    for(int i = 1; i <= n; i += 1)
        if(d[a[i] & 1 ^ 1][i] == maxn) cout << "-1 ";
        else cout << d[a[i] & 1 ^ 1][i] << " ";
}