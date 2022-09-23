#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400400;
const int mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int f[N];
int d[N];
map < int, int > c;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                c[a[i]] += 1;
        }

        for(auto p: c){
                f[p.se] += 1;
        }
        for(int i = n; i >= 1; i--){
                f[i] += f[i + 1];
        }

        int best = -1, X, Y, A = 0;
        for(int m = 1; m <= n; m++){
                int cur = f[m] * m + A;

                int g = cur / m;
                if(g * m > best && g >= m){
                        best = g * m;
                        X = g;
                        Y = m;
                }

                A += m * (f[m] - f[m + 1]);
        }

        cout << best << "\n";
        cout << X << " " << Y << "\n";
        vector < vector < int > > res(X);
        for(int i = 0; i < X; i++){
                res[i].resize(Y);
        }
        vector < pair < int, int > > G;
        vector < int > V;
        for(auto p: c){
                int g = min(p.se, Y);
                G.push_back({g, p.fi});
        }
        sort(G.begin(), G.end());
        while(!G.empty()){
                while(G.back().fi--){
                        V.push_back(G.back().se);
                }
                G.pop_back();
        }
        reverse(V.begin(), V.end());
        for(int i = 0; i < best; i++){
                res[((i / Y) + i % Y) % X][i % Y] = V.back();
                V.pop_back();
        }
        for(int i = 0; i < X; i++){
                for(int j = 0; j < Y; j++){
                        cout << res[i][j] << " ";
                }
                cout << "\n";
        }
}