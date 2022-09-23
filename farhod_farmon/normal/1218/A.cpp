#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")


#include <bits/stdc++.h>
 
#define fi first
#define se second
 
const int N = 15500;
 
using namespace std;
 
int n;
long long d[N];
long long f[N];
long long s[N];
vector < int > v[N];
vector < int > ord;
bool used[N];
vector < int > g;
 
bool dfs(int x, int p)
{
        g.push_back(x);
        used[x] = true;
        for(int y: v[x]){
                if(y == p){
                        continue;
                } else if(used[y]){
                        while(g.back() != y){
                                ord.push_back(g.back());
                                g.pop_back();
                        }
                        ord.push_back(y);
                        return true;
                } else{
                        if(dfs(y, x)){
                                return true;
                        }
                }
        }
        g.pop_back();
        return false;
}
 
void trace(int x, int p)
{
        s[x] = 1;
        for(int y: v[x]){
                if(used[y] || y == p){
                        continue;
                }
                trace(y, x);
                s[x] += s[y];
                d[x] += d[y];
                f[x] = max(f[x], f[y] - s[y] - d[y]);
        }
        f[x] += n + d[x];
        d[x] += s[x];
}
 
long long F[N];
long long D[N];
 
int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);
 
        cin >> n;
        for(int i = 1; i <= n; i++){
                int x, y;
                cin >> x >> y;
 
                x += 1;
                y += 1;
 
                v[x].push_back(y);
                v[y].push_back(x);
        }
 
        dfs(1, 1);
 
        for(int i = 1; i <= n; i++){
                used[i] = 0;
        }
        for(int x: ord){
                used[x] = true;
        }
 
        for(int x: ord){
                trace(x, x);
        }
 
        long long res = 0, S = 0, l = ord.size(), inf = 1e18;
        for(int x: ord){
                S += d[x];
        }
        vector < long long > shit(l + l + 5, 0);
        for(int i = 0; i < l + l + 4; i++){
                shit[i + 1] = s[ord[i % l]] + shit[i];
        }
        for(int i = l - 1; i > 0; i--){
                for(int j = 0; j < l; j++){
                        F[j] = D[j];
                        D[j] = inf;
                }
                for(int j = 0, h = i; j < l; j++, h++){
                        if(D[j] > F[j] + shit[h + 1] - shit[j]){
                                D[j] = F[j] + shit[h + 1] - shit[j];
                        }
                        if(j < l - 1){
                                if(D[j + 1] > F[j] + shit[h + 1] - shit[j]){
                                        D[j + 1] = F[j] + shit[h + 1] - shit[j];
                                }
                        } else{
                                if(D[0] > F[j] + shit[h + 1] - shit[j]){
                                        D[0] = F[j] + shit[h + 1] - shit[j];
                                }
                        }
                }
        }
 
        for(int i = 0; i < l; i++){
 
                long long cur = S;
                cur -= d[ord[i]];
                cur += f[ord[i]];
                cur += (l - 1) * n - D[i];
 
                res = max(res, cur);
        }
 
        cout << res << "\n";
}