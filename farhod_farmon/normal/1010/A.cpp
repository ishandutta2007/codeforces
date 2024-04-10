#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1010;
const long long Q = N * 30;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
long double m;
long double a[N], b[N];

bool can(long double x)
{
        for(int i = 1; i <= n; i++){
                x -= (x + m) / a[i];
                if(x < 0){
                        return false;
                }
                x -= (x + m) / b[i + 1];
                if(x < 0){
                        return false;
                }
        }
        return true;
}

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> b[i];
        }
        b[n + 1] = b[1];
        long double l = 0, r = 1e11;
        for(int i = 0; i < 500; i++){
                long double m = (l + r) / 2;
                if(can(m)){
                        r = m;
                }
                else{
                        l = m;
                }
        }
        if(l > 1e10){
                cout << -1 << "\n";
                return;
        }
        cout << fixed << setprecision(9) << l << "\n";
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