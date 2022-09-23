#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 50;

using namespace std;

vector < pair < int, int > > res;
pair < int, int > p[4];
bool used[1011][1011];

void add(vector < pair < int, int > > &v, int x, int y)
{
        if(used[x][y]){
                return;
        }
        used[x][y] = 1;
        v.push_back({x, y});
}

void go(vector < pair < int, int > > &v, int a, int b)
{
        int x = -1, y;
        int dist = 1e9;
        for(auto p: v){
                int cur = abs(p.fi - a) + abs(p.se - b);
                if(cur < dist){
                        dist = cur;
                        x = p.fi;
                        y = p.se;
                }
        }
        while(x > a){
                x--;
                add(v, x, y);
        }
        while(x < a){
                x++;
                add(v, x, y);
        }
        while(y > b){
                y--;
                add(v, x, y);
        }
        while(y < b){
                y++;
                add(v, x, y);
        }
}

void solve(int a, int b, int c)
{
        for(int it = 0; it < 2; it++){
                vector < pair < int, int > > v;
                int x = p[a].fi, y = p[a].se;
                add(v, x, y);
                go(v, p[b].fi, p[b].se);
                go(v, p[c].fi, p[c].se);
                for(auto p: v){
                        used[p.fi][p.se] = 0;
                }
                if(it == 1){
                        for(auto &p: v){
                                swap(p.fi, p.se);
                        }
                }
                if(res.empty() || v.size() < res.size()){
                        res = v;
                }
                for(int i = 1; i <= 3; i++){
                        swap(p[i].fi, p[i].se);
                }
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        for(int i = 1; i <= 3; i++){
                cin >> p[i].fi >> p[i].se;
        }
        solve(3, 1, 2);
        solve(2, 1, 3);
        solve(1, 2, 3);
        solve(1, 3, 2);
        solve(2, 3, 1);
        solve(3, 2, 1);
        cout << res.size() << "\n";
        for(auto p: res){
                cout << p.fi << " " << p.se << "\n";
        }
}