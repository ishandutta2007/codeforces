#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 366;
const long long Q = 1000010;
const long long mod = 1000000009;
const long long block = 500;

using namespace std;

int n;
int a[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                a[i] += a[i - 1];
        }
        int ans = 1e9;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= i; j++){
                        int x = a[i] - a[j - 1], y = 360 - x;
                        ans = min(ans, abs(x - y));
                }
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("park.in");
        //fout("park.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}