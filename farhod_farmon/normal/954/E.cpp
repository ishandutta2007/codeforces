#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
double T;
pair < double, double > a[N];

bool can(double m)
{
        double l = 0.0, r = 0.0, need = m;
        for(int i = 1; i <= n; i++){
                double g = min(a[i].se, need);
                l += g * a[i].fi;
                need -= g;
        }
        need = m;
        for(int i = n; i >= 1; i--){
                double g = min(a[i].se, need);
                r += g * a[i].fi;
                need -= g;
        }
        need = m * T;
        return l <= need && need <= r;
}

void solve()
{
        cin >> n >> T;
        for(int i = 1; i <= n; i++){
                cin >> a[i].se;
        }
        for(int i = 1; i <= n; i++){
                cin >> a[i].fi;
        }
        sort(a + 1, a + n + 1);
        double l = 0.0, r = 1e12;
        for(int i = 0; i < 200; i++){
                double m = (l + r) / 2.0;
                if(can(m)){
                        l = m;
                }
                else{
                        r = m;
                }
        }
        cout << fixed << setprecision(9) << l << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}