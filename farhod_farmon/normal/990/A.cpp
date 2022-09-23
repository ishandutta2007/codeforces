#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 13;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

long long n, m, a, b;

long long f(long long x)
{
        if(x > n){
                return (x - n) * a;
        }
        else{
                return (n - x) * b;
        }
}

void solve()
{
        cin >> n >> m >> a >> b;
        long long ans = 1e18;
        for(long long i = n / m - 1; i <= n / m + 1; i++){
                if(i < 0){
                        continue;
                }
                ans = min(ans, f(i * m));
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