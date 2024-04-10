#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 2020;
const long long Q = 1000100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int a[N];
int f[N];
int l[N];
int r[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                l[i] = l[i - 1] + (a[i] == 1);
        }
        for(int i = n; i >= 1; i--){
                r[i] = r[i + 1] + (a[i] == 2);
        }
        int ans = l[n];
        for(int i = 1; i <= n; i++){
                ans = max(ans, l[i - 1] + r[i]);
                int mx = - i + 1;
                for(int j = i; j <= n; j++){
                        f[j] = f[j - 1] + (a[j] == 2);
                        mx = max(mx, f[j] + f[j] - j);
                        ans = max(ans, mx + j - f[j] + l[i - 1] + r[j + 1]);
                }
                for(int j = i; j <= n; j++){
                        f[j] = 0;
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