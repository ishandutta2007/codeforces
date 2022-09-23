#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 2e18;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
long double R, d;

void solve()
{
        cin >> R >> d;
        cin >> n;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
                long double x, y, r;
                cin >> x >> y >> r;
                long double l = x * x + y * y;
                l = sqrt(l);
                if(l - r >= R - d && l + r <= R){
                        cnt++;
                }
        }
        cout << cnt << "\n";
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