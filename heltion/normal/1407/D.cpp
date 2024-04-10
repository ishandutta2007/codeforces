#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 300000 + 1;
vector<int> G[maxn];
int h[maxn], d[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1) cin >> h[i];
    for(int i = 1; i < n; i += 1)
        G[i].push_back(i + 1);
    stack<int> mx, mn;
    for(int i = 1; i <= n; i += 1){
        while(not mx.empty() and h[mx.top()] < h[i]) mx.pop();
        while(not mn.empty() and h[mn.top()] > h[i]) mn.pop();
        if(not mx.empty() and h[i - 1] < h[i])
            G[mx.top()].push_back(i);
        if(not mn.empty() and h[i - 1] > h[i])
            G[mn.top()].push_back(i);
        mx.push(i);
        mn.push(i);
    }
    while(not mx.empty()) mx.pop();
    while(not mn.empty()) mn.pop();
    for(int i = n; i >= 1; i -= 1){
        while(not mx.empty() and h[mx.top()] < h[i]) mx.pop();
        while(not mn.empty() and h[mn.top()] > h[i]) mn.pop();
        if(not mx.empty() and h[i + 1] < h[i])
            G[i].push_back(mx.top());
        if(not mn.empty() and h[i + 1] > h[i])
            G[i].push_back(mn.top());
        mx.push(i);
        mn.push(i);
    }
    for(int i = 1; i <= n; i += 1) d[i] = n;
    queue<int> q;
    d[1] = 0;
    q.push(1);
    while(not q.empty()){
        int u = q.front();
        q.pop();
        for(int v : G[u])
            if(d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                q.push(v);
            }
    }
    cout << d[n];
    return 0;
}