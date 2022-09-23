#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 2e18;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int m;
int d[N][2][2];

void solve()
{
        vector < int > a;
        a.push_back(0);
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                a.push_back(x);
                d[i][0][0] = -1e9;
                d[i][1][0] = -1e9;
                d[i][0][1] = -1e9;
                d[i][1][1] = -1e9;
        }
        d[0][0][0] = -1e9;
        d[0][1][0] = -1e9;
        a.push_back(m);
        for(int i = 1; i <= n + 1; i++){
                d[i][0][0] = d[i - 1][0][1] + a[i] - a[i - 1];
                d[i][0][1] = d[i - 1][0][0];
                d[i][1][0] = d[i - 1][1][1] + a[i] - a[i - 1];
                if(a[i - 1] + 1 < a[i]) d[i][1][0] = max(d[i][1][0], d[i - 1][0][0] + a[i] - a[i - 1] - 1);
                d[i][1][1] = d[i - 1][1][0];
                if(a[i - 1] + 1 < a[i]) d[i][1][1] = max(d[i][1][1], d[i - 1][0][1] + a[i] - a[i - 1] - 1);
        }
        n++;
        int ans = d[n][0][0];
        ans = max(ans, d[n][0][1]);
        ans = max(ans, d[n][1][0]);
        ans = max(ans, d[n][1][1]);
        cout << ans << "\n";
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