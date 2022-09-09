#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000;
int p[maxn];
int fp(int u){
    return u == p[u] ? u : p[u] = fp(p[u]);
}
int pre[26];
void unite(int u, int v){
    u = fp(u);
    v = fp(v);
    p[u] = v;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    fill(pre, pre + 26, -1);
    for(int i = 0; i < n; i += 1) p[i] = i;
    for(int i = 0; i < n; i += 1){
        string s;
        cin >> s;
        for(char c : s){
            if(~pre[c - 'a']) unite(pre[c - 'a'], i);
            pre[c - 'a'] = i;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i += 1) ans += p[i] == i;
    cout << ans;
    return 0;
}