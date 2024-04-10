#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int k;
int a[N];
int l[N];
int r[N];

void solve()
{
        cin >> n >> k;
        int mx = -1e9 - 1;
        l[0] = r[n + 1] = 1e9 + 1;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                mx = max(mx, a[i]);
                l[i] = min(l[i - 1], a[i]);
        }
        for(int i = n; i >= 1; i--){
                r[i] = min(r[i + 1], a[i]);
        }
        if(k == 1){
                cout << l[n] << "\n";
        }
        else if(k == 2){
                int ans = -1e9;
                for(int i = 1; i < n; i++){
                        ans = max(ans, max(l[i], r[i + 1]));
                }
                cout << ans << "\n";
        }
        else{
                cout << mx << "\n";
        }
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