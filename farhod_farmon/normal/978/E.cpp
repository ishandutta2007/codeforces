#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int w;

void solve()
{
        cin >> n >> w;
        int l = 0, r = w, s = 0;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                s += x;
                r = min(r, w - s);
                l = max(l, 0 - s);
        }
        cout << max(0, r - l + 1) << "\n";
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