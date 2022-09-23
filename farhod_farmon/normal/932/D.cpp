#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 400400;
const long long Q = 1000100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int q;
int f[N][21];
int d[N][21];
long long c[N][21];
long long mx[N][21];

void add(int x, int p, long long a)
{
        f[x][0] = p;
        mx[x][0] = a;
        for(int i = 1; i < 21; i++){
                f[x][i] = f[f[x][i - 1]][i - 1];
                mx[x][i] = max(mx[x][i - 1], mx[f[x][i - 1]][i - 1]);
        }
        if(mx[p][20] < a){
                for(int i = 0; i < 21; i++){
                        d[x][i] = c[x][i] = -1;
                }
                return;
        }
        int fi = p;
        for(int i = 20; i >= 0; i--){
                if(mx[fi][i] < a){
                        fi = f[fi][i];
                }
        }
        d[x][0] = fi;
        c[x][0] = mx[fi][0];
        for(int i = 1; i < 21; i++){
                if(d[x][i - 1] == -1){
                        d[x][i] = c[x][i] = -1;
                        continue;
                }
                d[x][i] = d[d[x][i - 1]][i - 1];
                c[x][i] = c[x][i - 1] + c[d[x][i - 1]][i - 1];
        }
}

int get(int x, long long g)
{
        if(mx[x][0] > g){
                return 0;
        }
        int l = 1;
        g -= mx[x][0];
        for(int i = 20; i >= 0; i--){
                if(d[x][i] == -1){
                        continue;
                }
                if(c[x][i] <= g){
                        l += (1 << i);
                        g -= c[x][i];
                        x = d[x][i];
                }
        }
        return l;
}

void solve()
{
        for(int i = 0; i < 21; i++){
                f[1][i] = 1;
                d[1][i] = -1;
        }
        long long last = 0, cnt = 1;
        cin >> q;
        for(int i = 1; i <= q; i++){
                long long t, r, x;
                cin >> t >> r >> x;
                r ^= last;
                x ^= last;
                if(t == 1){
                        cnt++;
                        add(cnt, r, x);
                }
                else{
                        last = get(r, x);
                        cout << last << "\n";
                }
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("bootfall.in");
        //fout("bootfall.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}