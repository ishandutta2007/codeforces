#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 10001;
const long long mod = 1e9 + 7;;
const long long block = sqrt(N);

using namespace std;

int n;
long double x[N];
long double y[N];

bool can(long double m)
{
        long double tl = -1e18, tr = 1e18;
        for(int i = 1; i <= n; i++){
                if(y[i] > m + m){
                        return false;
                }
                /*long double l = x[i], r = 1e18;
                for(int it = 0; it < 100; it++){
                        long double m2 = (l + r) / 2;
                        if((x[i] - m2) * (x[i] - m2) + (y[i] - m) * (y[i] - m) <= m * m){
                                l = m2;
                        }
                        else{
                                r = m2;
                        }
                }*/
                long double a = 1, b = - 2 * x[i], c = x[i] * x[i] + y[i] * y[i] - 2 * y[i] * m;
                long double d = sqrt(b * b - 4 * a * c);
                long double r1 = (- b - d) / (a + a), r2 = (- b + d) / (a + a);
                if(r1 > r2){
                        swap(r1, r2);
                }
                tr = min(tr, r2);
                tl = max(tl, r1);
        }
        return tl <= tr;
}

void solve()
{
        cin >> n;
        bool neg = false, pos = false;
        for(int i = 1; i <= n; i++){
                cin >> x[i] >> y[i];
                if(y[i] < 0){
                        neg = true;
                }
                else if(y[i] > 0){
                        pos = true;
                }
        }
        if(neg && pos){
                cout << -1 << "\n";
                return;
        }
        if(neg){
                for(int i = 1; i <= n; i++){
                        y[i] = - y[i];
                }
        }
        long double l = 0, r = 1e14;
        for(int it = 0; it < 160; it++){
                long double m = (l + r) / 2;
                if(can(m)){
                        r = m;
                }
                else{
                        l = m;
                }
        }
        cout << fixed << setprecision(7) << l << "\n";
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