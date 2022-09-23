#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long Q = 200200;
const long long mod = 998244353;
const long long MAGIC = sqrt(N);

using namespace std;

int n;
int l[N];
int r[N];
int d1[N];
int d2[N];
int d3[N];
int d4[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> l[i] >> r[i];
        }
        d2[0] = d4[n + 1] = 1e9;
        for(int i = 1; i <= n; i++){
                d1[i] = max(d1[i - 1], l[i]);
                d2[i] = min(d2[i - 1], r[i]);
        }
        for(int i = n; i >= 1; i--){
                d3[i] = max(d3[i + 1], l[i]);
                d4[i] = min(d4[i + 1], r[i]);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
                int tl = max(d1[i - 1], d3[i + 1]);
                int tr = min(d2[i - 1], d4[i + 1]);
                ans = max(ans, tr - tl);
        }
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