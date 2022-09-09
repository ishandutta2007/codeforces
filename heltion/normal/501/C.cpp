#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1 << 16;
int d[maxn], s[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; i += 1) cin >> d[i] >> s[i];
    queue<int> q;
    vector<pair<int, int>> vp;
    for(int i = 0; i < n; i += 1) if(d[i] == 1) q.push(i);
    while(not q.empty()){
        int u = q.front();
        q.pop();
        if(not d[u]) continue;
        vp.push_back({u, s[u]});
        s[s[u]] ^= u;
        if((d[s[u]] -= 1) == 1) q.push(s[u]);
    }
    cout << vp.size() << "\n";
    for(auto [x, y] : vp) cout << x << " " << y << "\n";
    return 0;
}