#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 2020;
const long long Q = 10001;
const long long mod = 998244353;
const long long block = sqrt(N);

using namespace std;

int n;
int k;
int d[N][N];
char c[N][N];
bool used[N][N];

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        cin >> c[i][j];
                }
        }
        for(int i = 0; i <= n; i++){
                for(int j = 0; j <= n; j++){
                        d[i][j] = 1e9;
                }
        }
        d[0][1] = 0;
        int mx = 0;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        int w = (c[i][j] != 'a');
                        d[i][j] = min(d[i - 1][j], d[i][j - 1]) + w;
                        if(d[i][j] <= k){
                                mx = max(mx, i + j - 1);
                        }
                }
        }
        for(int i = 0; i < mx; i++){
                cout << 'a';
        }
        vector < pair < int, int > > q;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        if(i + j - 1 == mx && d[i][j] <= k){
                                q.push_back({i, j});
                        }
                }
        }
        if(mx == 0){
                cout << c[1][1];
                q.push_back({1, 1});
        }
        while(!q.empty()){
                char best = 'z';
                vector < pair < int, int > > nq;
                for(auto p: q){
                        if(used[p.fi + 1][p.se] == 0 && p.fi + 1 <= n){
                                used[p.fi + 1][p.se] = 1;
                                if(c[p.fi + 1][p.se] < best){
                                        nq.clear();
                                        best = c[p.fi + 1][p.se];
                                        nq.push_back({p.fi + 1, p.se});
                                }
                                else if(c[p.fi + 1][p.se] == best){
                                        nq.push_back({p.fi + 1, p.se});
                                }
                        }
                        if(used[p.fi][p.se + 1] == 0 && p.se + 1 <= n){
                                used[p.fi][p.se + 1] = 1;
                                if(c[p.fi][p.se + 1] < best){
                                        nq.clear();
                                        best = c[p.fi][p.se + 1];
                                        nq.push_back({p.fi, p.se + 1});
                                }
                                else if(c[p.fi][p.se + 1] == best){
                                        nq.push_back({p.fi, p.se + 1});
                                }
                        }
                }
                if(!nq.empty()){
                        cout << best;
                }
                q = nq;
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("distance.in");
        //fout("distance.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}