#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int a[N];
int A;
vector < int > v[N];
vector < pair < int, int > > res;

void dfs(int x, int p, int st)
{
        res.push_back({x, st});
        int need = st - 1, rem = 0;
        for(int y: v[x]) if(y != p) rem += 1;
        bool done = false;
        for(int y: v[x]) if(y != p){
                if(st == A){
                        st = need - rem;
                        res.push_back({x, st});
                        done = true;
                }
                st += 1;
                rem -= 1;
                dfs(y, x, st);
                res.push_back({x, st});
        }
        if(!done){
                res.push_back({x, need});
        }
}

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        if(n == 1){
                cout << 1 << "\n";
                cout << 1 << " " << 0 << "\n";
                return 0;
        }
        for(int i = 1; i <= n; i++){
                A = max(A, (int)v[i].size());
        }

        res.push_back({1, 0});
        for(int i = 0; i < v[1].size(); i++){
                dfs(v[1][i], 1, i + 1);
                res.push_back({1, i + 1});
        }

        cout << res.size() << "\n";
        for(auto p: res) cout << p.fi << " " << p.se << "\n";
}