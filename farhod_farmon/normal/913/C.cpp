#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 5000010;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
long long l;
long long c[N];

void solve()
{
        cin >> n >> l;
        for(int i = 0; i < n; i++){
                cin >> c[i];
        }
        for(int i = n; i < 31; i++){
                c[i] = 1e18;
        }
        for(int i = 1; i < 31; i++){
                c[i] = min(c[i], c[i - 1] + c[i - 1]);
        }
        long long ans = 0, mn = 1e18;
        for(int i = 30; i >= 0; i--){
                if(l >= (1 << i)){
                        l -= (1 << i);
                        ans += c[i];
                }
                mn = min(mn, ans + c[i]);
        }
        ans = min(mn, ans);
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