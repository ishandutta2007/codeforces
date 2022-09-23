#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 6000100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;

void solve()
{
        int ans = -1e9;
        cin >> n;
        for(int i = 1; i <= n; i++){
                int x, g = 0;
                cin >> x;
                for(int j = 0; j * j <= x; j++){
                        if(j * j == x){
                                g = 1;
                        }
                }
                if(!g){
                        ans = max(ans, x);
                }
        }
        cout << ans << "\n";
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