#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 220;
const long long Q = 6000100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int k;
int a[N];
bool used[N];

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= k; i++){
                cin >> a[i];
        }
        for(int ans = 1; ; ans++){
                for(int i = 1; i <= n; i++){
                        used[i] = 0;
                }
                for(int i = 1; i <= k; i++){
                        int l = (a[i] - ans + 1), r = (a[i] + ans - 1);
                        l = max(l, 1); r = min(r, n);
                        for(int j = l; j <= r; j++){
                                used[j] = 1;
                        }
                }
                bool can = 1;
                for(int i = 1; i <= n; i++){
                        can &= used[i];
                }
                if(can){
                        cout << ans << "\n";
                        return;
                }
        }
}

bool mtest = true; int main()
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