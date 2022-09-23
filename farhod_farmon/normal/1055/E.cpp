#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1555;
const long long mod = 998244353;

using namespace std;

int n;
int s;
int m;
int k;
int a[N];
int p[N];
int d[N];
int f[N];
int best[N];
int g[N][12];
int L[N];
vector < int > v[N];

int get(int l, int r)
{
        int gg = L[r - l + 1];
        return max(g[l][gg], g[r - (1 << gg) + 1][gg]);
}

bool can(int m)
{
        for(int i = 1; i <= n; i++){
                p[i] = p[i - 1] + (a[i] <= m);
        }
        for(int i = 1; i <= n; i++){
                d[i] = f[i] = best[i] = 0;
        }
        for(int h = 1; h <= ::m; h++){
                for(int i = 1; i <= n; i++){
                        g[i][0] = f[i] - p[i];
                }
                for(int j = 1; j < 12; j++){
                        for(int i = 1; i <= n; i++){
                                if(i + (1 << j) - 1 > n){
                                        break;
                                }
                                g[i][j] = max(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
                        }
                }
                for(int i = 1; i <= n; i++){
                        for(int r: v[i]){
                                d[r] = max(d[r], best[i - 1] + p[r] - p[i - 1]);
                                d[r] = max(d[r], get(i, r) + p[r]);
                        }
                        if(d[i] >= k){
                                return true;
                        }
                }
                for(int i = 1; i <= n; i++){
                        f[i] = max(f[i], d[i]);
                        best[i] = max(best[i - 1], f[i]);
                        d[i] = 0;
                }
        }
        return false;
}

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        vector < int > g;
        cin >> n >> s >> m >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                g.push_back(a[i]);
        }
        for(int i = 1; i <= s; i++){
                int l, r;
                cin >> l >> r;
                v[l].push_back(r);
        }
        for(int i = 2; i < N; i++){
                L[i] = L[i / 2] + 1;
        }
        sort(g.begin(), g.end());
        int l = 0, r = g.size();
        while(l < r){
                int m = (l + r) / 2;
                if(can(g[m])){
                        r = m;
                }
                else{
                        l = m + 1;
                }
        }
        if(l == g.size()){
                cout << -1 << "\n";
        }
        else{
                cout << g[l] << "\n";
        }
}