#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 2000000 + 1;
constexpr int maxk = 21;
int d[1 << maxk], from[1 << maxk];
int p[maxn][maxk], q[maxk];
int F[maxn], G[maxn];
int a[maxn], b[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    string s, t;
    cin >> s >> t;
    for(int j = 0; j < k; j += 1) p[0][j] = j;
    for(int i = 1; i <= n; i += 1){
        cin >> a[i] >> b[i];
        a[i] -= 1;
        b[i] -= 1;
        for(int j = 0; j < k; j += 1) q[j] = j;
        swap(q[a[i]], q[b[i]]);
        for(int j = 0; j < k; j += 1) p[i][j] = q[p[i - 1][j]];
        //for(int j = 0; j < k; j += 1)
        //    cout << p[i][j] << " ";
        //cout << "\n";
    }
    for(int i = 0; i <= n; i += 1){
        for(int j = 0; j < k; j += 1){
            F[i] |= (t[p[i][j]] - '0') << j;
            G[i] |= (s[p[i][j]] - '0') << j;
        }
    }
    queue<int> q;
    fill(d, d + (1 << k), maxn + 1);
    int ans = k + 1, l = -1, r = -1;
    for(int j = 0; j + m <= n; j += 1){
        q.push(G[j]);
        d[G[j]] = 0;
        from[G[j]] = j;
        while(not q.empty()){
            int u = q.front();
            q.pop();
            for(int i = 0; i < k; i += 1) if(d[u ^ (1 << i)] > d[u] + 1){
                d[u ^ (1 << i)] = d[u] + 1;
                from[u ^ (1 << i)] = from[u];
                q.push(u ^ (1 << i));
            }
        }
        if(d[F[j + m]] < ans){
            ans = d[F[j + m]];
            l = from[F[j + m]] + 1;
            r = j + m;
        }
    }
    cout << k - ans << "\n" << l << " " << r << "\n";
    return 0;
}