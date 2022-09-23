#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200100;
const long long Q = N * 30;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int k;
int a[N];

void solve()
{
        double ans = 0;
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                int s = 0;
                for(int j = i; j >= 1; j--){
                        s += a[j];
                        if(i - j + 1 >= k){
                                ans = max(ans, 1.0 * s / (i - j + 1));
                        }
                }
        }
        cout << fixed << setprecision(9) << ans << "\n";
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