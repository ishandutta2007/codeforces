#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 2020;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
int p;
int a[N];
int b[N];

void solve()
{
        cin >> n >> k >> p;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= k; i++){
                cin >> b[i];
        }
        sort(a + 1, a + n + 1);
        sort(b + 1, b + k + 1);
        int ans = 2e9;
        for(int i = 1; i + n - 1 <= k; i++){
                int cnt = 0;
                for(int j = 1; j <= n; j++){
                        cnt = max(cnt, abs(a[j] - b[i + j - 1]) + abs(b[i + j - 1] - p));
                }
                ans = min(ans, cnt);
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}