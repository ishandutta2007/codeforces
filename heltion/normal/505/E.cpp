#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 100000;
using LL = long long;
LL h[maxn], a[maxn], H[maxn];
struct cmp{
    bool operator()(const int& x, const int &y){
        return H[x] / a[x] > H[y] / a[y];
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k, p;
    cin >> n >> m >> k >> p;
    for(int i = 0; i < n; i += 1) cin >> h[i] >> a[i];
    LL L = 1, R = 1'000'000'000'000'000'000;
    while(L < R){
        LL M = (L + R) >> 1;
        fill(H, H + n, M);
        priority_queue<int, vector<int>, cmp> q;
        for(int i = 0; i < n; i += 1) if(H[i] - m * a[i] < h[i]) q.push(i);
        int ok = 1;
        for(int i = 1; i <= m; i += 1) if(not q.empty()){
            if(H[q.top()] < i * a[q.top()]){
                ok = 0;
                break;
            }
            for(int j = 0; j < k; j += 1) if(not q.empty()){
                int u = q.top();
                q.pop();
                H[u] += p;
                if(H[u] - m * a[u] < h[u]) q.push(u);
            }
        }
        for(int i = 0; i < n; i += 1) if(H[i] - a[i] * m < h[i]) ok = 0;
        if(ok) R = M;
        else L = M + 1;
    }
    cout << L;
    return 0;
}