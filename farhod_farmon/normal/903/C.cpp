#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 1000010;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
map < int, int > c;

void solve()
{
        cin >> n;
        int ans = 0, x;
        for(int i = 1; i <= n; i++){
                cin >> x;
                c[x]++;
                ans = max(ans, c[x]);
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("game.in");
        //fout("game.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}