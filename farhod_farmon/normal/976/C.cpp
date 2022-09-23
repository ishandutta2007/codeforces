#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long Q = 101;
const long long mod = 1e9 + 7;
const long long block = 250;

using namespace std;

int n;
pair < pair < int, int >, int > p[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                int l, r;
                cin >> l >> r;
                p[i] = {{r, -l}, i};
        }
        sort(p + 1, p + n + 1);
        int j = 0, mx = 0;
        for(int i = 1; i <= n; i++){
                int l = -p[i].fi.se, r = p[i].fi.fi, h = p[i].se;
                if(mx >= l){
                        cout << j << " " << h << "\n";
                        return;
                }
                if(l > mx){
                        mx = l;
                        j = h;
                }
        }
        cout << -1 << " " << -1 << "\n";
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