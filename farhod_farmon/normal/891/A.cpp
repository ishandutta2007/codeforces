#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 2020;
const long long Q = 10010;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int a[N];

void solve()
{
        int cnt = 0;
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                cnt += a[i] == 1;
        }
        if(cnt > 0){
                cout << n - cnt << "\n";
                return;
        }
        int ans = 1e9;
        for(int i = 1; i <= n; i++){
                int g = a[i];
                for(int j = 0; i + j <= n; j++){
                        g = __gcd(g, a[i + j]);
                        if(g == 1){
                                ans = min(ans, j + n - 1);
                                break;
                        }
                }
        }
        if(ans == 1e9){
                ans = -1;
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("mine.in");
        //fout("mine.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}