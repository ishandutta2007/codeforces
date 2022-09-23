#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 70070;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

long long w[4][4];
long long x[4][4];
long long y[4][4];
long long used[4][4];
long long k, a, b;
pair < long long, long long > p[4][4];

void solve()
{
        w[1][3] = w[3][2] = w[2][1] = 1;
        cin >> k >> a >> b;
        if(k == 1){
                cout << w[a][b] << " " << w[b][a] << "\n";
                return;
        }
        k--;
        for(int i = 1; i <= 3; i++){
                for(int j = 1; j <= 3; j++){
                        cin >> x[i][j];
                }
        }
        for(int i = 1; i <= 3; i++){
                for(int j = 1; j <= 3; j++){
                        cin >> y[i][j];
                }
        }
        long long g = 0;
        long long a1 = w[a][b], a2 = w[b][a];
        while(k){
                k--;
                g++;
                int na = x[a][b], nb = y[a][b];
                a1 += w[na][nb];
                a2 += w[nb][na];
                if(used[na][nb]){
                        long long l = (g - used[na][nb]);
                        long long d = k / l;
                        k %= l;
                        a1 += d * (a1 - p[na][nb].fi);
                        a2 += d * (a2 - p[na][nb].se);
                        a = na; b = nb;
                        break;
                }
                a = na; b = nb;
                used[a][b] = g;
                p[a][b] = {a1, a2};
        }
        while(k){
                k--;
                int na = x[a][b], nb = y[a][b];
                a1 += w[na][nb];
                a2 += w[nb][na];
                a = na; b = nb;
        }
        cout << a1 << " " << a2 << "\n";
}


bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}