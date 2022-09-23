#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 10100;
const long long Q = 1000100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
long long W;
long long B;
long long X;
long long c[N];
long long d[N];
long long cost[N];

void solve()
{
        cin >> n >> W >> B >> X;
        for(int i = 0; i < N; i++){
                d[i] = -1;
        }
        d[0] = W;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> cost[i];
        }
        for(int i = 1; i <= n; i++){
                for(long long j = 0; j <= c[i - 1]; j++){
                        if(d[j] >= 0){
                                d[j] = min(W + j * B, d[j] + X);
                        }
                }
                for(int j = 0; j < c[i]; j++){
                        for(long long h = c[i - 1] + j; h >= 0; h--){
                                if(d[h] >= 0){
                                        d[h + 1] = max(d[h + 1], min(W + h * B, d[h] - cost[i]));
                                }
                        }
                }
                c[i] += c[i - 1];
        }
        int ans = 0;
        while(d[ans] >= 0){
                ans++;
        }
        cout << ans - 1 << "\n";
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