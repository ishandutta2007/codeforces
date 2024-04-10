#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int a[N];
int b[N];
int c[N];
bool used[N];
vector < pair < int, int > > res;

void make(int x, int y)
{
        b[x] ^= 1;
        b[y] ^= 1;
        swap(a[x], a[y]);
        swap(c[a[x]], c[a[y]]);
        res.push_back({a[x], a[y]});
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                c[a[i]] = i;
        }

        for(int i = 1; i <= n; i++){
                swap(a[i], c[i]);
        }

        vector < vector < int > > C;
        for(int i = 1; i <= n; i++){
                if(used[i]){
                        continue;
                }
                C.push_back({i});
                int x = a[i];
                while(x != i){
                        C.back().push_back(x);
                        used[x] = true;
                        x = a[x];
                }
        }

        if(C.size() == 1){
                make(C.back()[0], C.back()[1]);
                make(C.back()[1], C.back()[n - 1]);
        } else if(C.size() % 2 == 0){
                for(int i = 0; i < C.size(); i += 2){
                        make(C[i][0], C[i + 1][0]);
                }
        } else{
                make(C[0][0], C[1][0]);
                make(C[1][0], C[2][0]);
                for(int i = 3; i < C.size(); i += 2){
                        make(C[i][0], C[i + 1][0]);
                }
        }

        for(int i = 1; i <= n; i++){
                used[i] = 0;
        }

        for(int i = 1; i <= n; i++){
                //cout << a[i] << " ";
                //assert(a[i] == i);
        }
        //cout << "\n";

        vector < int > g;
        for(int i = 1; i <= n; i++){
                if(a[i] == i || used[i]){
                        continue;
                }
                g.clear();
                g.push_back(i);
                int x = a[i];
                while(x != i){
                        used[x] = true;
                        g.push_back(x);
                        x = a[x];
                }

                int X = -1, Y = -1;
                for(int i = 0; i < g.size(); i++){
                        if(b[g[i]]){
                                if(X == -1){
                                        X = i;
                                } else{
                                        Y = i;
                                }
                        }
                        //cout << g[i] << " ";
                }
                //cout << X << " " << Y << "\n";

                for(int i = Y; i - 1 > X; i--){
                        make(g[i], g[i - 1]);
                }
                for(int i = X; i > 0; i--){
                        make(g[i], g[i - 1]);
                }

                if(Y + 1 < g.size()){
                        make(g[0], g[g.size() - 1]);
                        for(int i = g.size() - 2; i > Y; i--){
                                make(g[i], g[i + 1]);
                        }
                        make(g[Y + 1], g[X + 1]);
                } else{
                        make(g[0], g[X + 1]);
                }

        }
        for(int i = 1; i <= n; i++){
                //cout << a[i] << " ";
                assert(a[i] == i);
        }
        //cout << "\n";
        cout << res.size() << "\n";
        for(auto p: res){
                cout << p.fi << " " << p.se << "\n";
        }
}