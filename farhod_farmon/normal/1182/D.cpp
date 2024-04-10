#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod1 = 1e9 + 9;
const long long mod2 = 1e9 + 7;

using namespace std;

long long good(long long x)
{
        for(long long i = 2; i * i <= x; i++){
                if(x % i == 0){
                        return good(x + 1);
                }
        }
        return x;
}

long long p1 = 100003;
long long p2 = 103007;

int n;
long long d1[N];
long long d2[N];
vector < int > v[N];

void dfs(int x, int p)
{
        long long a1 = 1e10, a2 = 1e10, b1 = 0, b2 = 0, cnt = 1;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                cnt += 1;
                dfs(y, x);
                if(d1[y] == -1 || d2[y] == -1){
                        d1[x] = d2[x] = -1;
                }
                a1 = min(a1, d1[y]);
                a2 = min(a2, d2[y]);
                b1 = max(b1, d1[y]);
                b2 = max(b2, d2[y]);
        }
        if(a1 == -1 || a2 == -1 || d1[x] == -1){
                d1[x] = d2[x] = -1;
                return;
        } else if(cnt > 1){
                if(a1 != b1 || a2 != b2){
                        d1[x] = d2[x] = -1;
                        return;
                }
                d1[x] = a1;
                d2[x] = a2;
        }
        d1[x] = (d1[x] * p1 + cnt) % mod1;
        d2[x] = (d2[x] * p2 + cnt) % mod2;
}

void solve(int x, int p, long long f1, long long f2)
{
        int bad = 0;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                if((d1[y] != f1 || d2[y] != f2)){
                        bad += 1;
                }
        }
        if(bad > 1){
                return;
        } else if(bad == 0){
                cout << x << "\n";
                exit(0);
        }
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                if((d1[y] != f1 || d2[y] != f2)){
                        int cnt = v[x].size();
                        f1 = (f1 * p1 + cnt) % mod1;
                        f2 = (f2 * p2 + cnt) % mod2;
                        solve(y, x, f1, f2);
                        break;
                }
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        if(n == 1){
                cout << 1 << "\n";
                return 0;
        }
        p1 = good(p1);
        p2 = good(p2);
        dfs(2, 2);
        if(d1[2] != -1){
                cout << 2 << "\n";
                return 0;
        }
        int bad = v[2][0];
        for(int y: v[2]){
                if(d1[y] != d1[bad] || d2[y] != d2[bad] || d1[y] == -1){
                        bad = y;
                        break;
                }
        }
        for(int can: {v[2][0], bad}){
                if(v[2].size() == 1){
                        solve(can, 2, 1, 1);
                        break;
                }
                long long A = -1, B = -1;
                for(int y: v[2]){
                        if(y == can){
                                continue;
                        }
                        if(d1[y] == -1){
                                A = -1;
                                break;
                        }
                        if(A == -1){
                                A = d1[y];
                                B = d2[y];
                                continue;
                        }
                        if(A != d1[y] || B != d2[y]){
                                A = -1;
                                break;
                        }
                }
                if(A == -1){
                        continue;
                }
                int cnt = v[2].size();
                A = (A * p1 + cnt) % mod1;
                B = (B * p2 + cnt) % mod2;
                solve(can, 2, A, B);
        }
        cout << -1 << "\n";
}