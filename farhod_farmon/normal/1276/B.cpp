#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 1e9 + 7;

using namespace std;

int n;
int m;
int p[N];
int s[N];
int inc[N];
vector < int > v[N];

int get(int x)
{
        return p[x] == x ? x : p[x] = get(p[x]);
}

void solve()
{
        int A, B;
        cin >> n >> m >> A >> B;
        for(int i = 1; i <= n; i++){
                p[i] = i;
                s[i] = 1;
                inc[i] = 0;
                v[i].clear();
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);

                if(x == A || x == B || y == A || y == B){
                        continue;
                }
                x = get(x);
                y = get(y);
                if(x != y){
                        p[x] = y;
                        s[y] += s[x];
                }
        }

        int X = 0, Y = 0;
        for(int x: v[A]){
                if(x == B){
                        continue;
                }
                inc[get(x)] |= 1;
        }
        for(int x: v[B]){
                if(x == A){
                        continue;
                }
                inc[get(x)] |= 2;
        }
        for(int i = 1; i <= n; i++){
                if(get(i) != i){
                        continue;
                }
                if(inc[i] == 1){
                        X += s[i];
                } else if(inc[i] == 2){
                        Y += s[i];
                }
        }
        cout << 1ll * X * Y << "\n";
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                solve();
        }
}