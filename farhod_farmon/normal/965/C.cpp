#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 210;
const long long Q = 101;
const long long mod = 1e9 + 7;
const long long block = 250;

using namespace std;

long long n, k, m, d;

void solve()
{
        cin >> n >> k >> m >> d;
        long long ans = 0;
        for(long long f = 1; f <= d; f++){
                long long l = 0, r = m;
                while(l < r){
                        long long tm = (l + r) / 2 + 1;
                        if((long double)tm <= (long double)n / k / (f - 1) && n - (f - 1) * k * tm >= tm){
                                l = tm;
                        }
                        else{
                                r = tm - 1;
                        }
                }
                ans = max(ans, f * l);
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}