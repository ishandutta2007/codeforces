#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200100;
const long long Q = N * 30;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
int a[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n + n; i++){
                cin >> a[i];
        }
        sort(a + 1, a + n + n + 1);
        long long ans = 1ll * (a[n] - a[1]) * (a[n + n] - a[n + 1]);
        for(int i = 2; i <= n; i++){
                ans = min(ans, 1ll * (a[n + i - 1] - a[i]) * (a[n + n] - a[1]));
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