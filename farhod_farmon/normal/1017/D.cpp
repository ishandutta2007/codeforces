#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 110;
const long long Q = N * 30;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
int m;
int q;
int w[N];
int c[1 << 6][1 << 6];
int d[1 << 6][1 << 6][N];

void solve()
{
        cin >> n >> m >> q;
        for(int i = 0; i < n; i++){
                cin >> w[i];
        }
        int half = (1 << 6) - 1;
        for(int i = 1; i <= m; i++){
                int mask = 0;
                for(int i = 0; i < n; i++){
                        char c;
                        cin >> c;
                        mask += ((c - '0') << i);
                }
                c[mask & half][mask >> 6]++;
        }
        for(int i = 0; i < (1 << 6); i++){
                for(int j = 0; j < (1 << 6); j++){
                        for(int h = 0; h < (1 << 6); h++){
                                int sum = 0;
                                for(int k = 0; k < 6; k++){
                                        if(((j >> k) & 1) == ((h >> k) & 1)){
                                                sum += w[6 + k];
                                        }
                                }
                                d[i][j][sum] += c[i][h];
                        }
                        for(int h = 1; h < N; h++){
                                d[i][j][h] += d[i][j][h - 1];
                        }
                }
        }
        for(int i = 1; i <= q; i++){
                int mask = 0, k;
                for(int j = 0; j < n; j++){
                        char c;
                        cin >> c;
                        mask += ((c - '0') << j);
                }
                cin >> k;
                int ans = 0;
                for(int j = 0; j < (1 << 6); j++){
                        int sum = 0;
                        for(int h = 0; h < 6; h++){
                                if(((mask >> h) & 1) == ((j >> h) & 1)){
                                        sum += w[h];
                                }
                        }
                        if(sum <= k){
                                ans += d[j][mask >> 6][k - sum];
                        }
                }
                cout << ans << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}