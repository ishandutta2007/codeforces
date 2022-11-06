#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 500000;
int a[4];
int c[6];
int d[5], v[maxn], nxt[maxn], g[maxn], vis[maxn], ans[maxn], cnt, ed;
void add(int x, int y){
    d[x] ++; d[y] --;
    v[++ed]=y;nxt[ed]=g[x];g[x]=ed;
}
void dfs(int x){
    for(int&i=g[x];i;){
        if(vis[i]){i=nxt[i];continue;};
        vis[i]=1;
        int j=i;
        dfs(v[i]);
        ans[++cnt]=v[j];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int i = 0; i < 4; i += 1) cin >> a[i];
    if(a[0] + a[1] + a[2] + a[3] == 1){
        cout << "YES\n";
        for(int i = 0; i < 4; i += 1) if(a[i]) cout << i;
        return 0;
    }
    for(int p = 0; p < 4; p += 1)
        for(int q = 0; q < 4; q += 1){
            if(a[p] == 0 or a[q] == 0 or (p == q and a[p] < 2)) continue;
            int b[4];
            for(int i = 0; i < 4; i += 1) b[i] = a[i];
            //01 10 12 21 23 32
            //c[1] + (p == 0) = a[0]
            //c[0] + (q == 0) = a[0]
            //c[0] + c[3] + (p == 1) = a[1]
            //c[1] + c[2] + (q == 1) = a[1]
            //c[2] + c[5] + (p == 2) = a[2]
            //c[4] + c[3] + (q == 2) = a[2]
            //c[4] + (p == 3) = a[3]
            //c[5] + (q == 3) = a[3]
            c[1] = a[0] - (p == 0);
            c[0] = a[0] - (q == 0);
            c[4] = a[3] - (p == 3);
            c[5] = a[3] - (q == 3);
            c[3] = a[1] - (p == 1) - c[0];
            c[2] = a[1] - (q == 1) - c[1];
            bool ok = c[2] + c[5] + (p == 2) == a[2] and c[4] + c[3] + (q == 2) == a[2];
            for(int i = 0; i < 6; i += 1) ok &= c[i] >= 0;
            //cout << p << " " << q << " " << ok << "\n";
            //for(int j = 0; j < 6; j += 1) cout << c[j] << " "; cout << "\n";
            if(ok){
                //cout << p << " " << q << "\n";
                //for(int j = 0; j < 6; j += 1) cout << c[j] << " "; cout << "\n";
                ed = cnt = 0;
                fill(d, d + 5, 0);
                fill(v, v + maxn, 0);
                fill(nxt, nxt + maxn, 0);
                fill(g, g + maxn, 0);
                fill(vis, vis + maxn, 0);
                fill(ans, ans + maxn, 0);
                add(4, p);
                add(q, 4);
                for(int i = 0; i < c[0]; i += 1) add(0, 1);
                for(int i = 0; i < c[1]; i += 1) add(1, 0);
                for(int i = 0; i < c[2]; i += 1) add(1, 2);
                for(int i = 0; i < c[3]; i += 1) add(2, 1);
                for(int i = 0; i < c[4]; i += 1) add(2, 3);
                for(int i = 0; i < c[5]; i += 1) add(3, 2);
                dfs(4);
                if(cnt != a[0] + a[1] + a[2] + a[3] + 1) continue;
                cout << "YES\n"; 
                for(int i = 2; i <= cnt; i += 1) cout << ans[i] << " ";
                return 0;
            }
        }
    cout << "NO";
    return 0;
}