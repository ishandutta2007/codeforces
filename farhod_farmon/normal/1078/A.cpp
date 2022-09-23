#include <bits/stdc++.h>7

#define fi first
#define se second

const int N = 110;
const long long mod = 1e18;

using namespace std;

long double a, b, c;

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        long double x1, y1, x2, y2;
        cin >> a >> b >> c;
        cin >> x1 >> y1 >> x2 >> y2;
        vector < pair < pair < long double, long double >, long double > > v, g;
        long double ans = fabs(x1 - x2) + fabs(y1 - y2);
        if(b != 0){
                long double y = (- c - a * x1) / b;
                v.push_back({{x1, y}, fabs(y1 - y)});
                y = (- c - a * x2) / b;
                g.push_back({{x2, y}, fabs(y2 - y)});
        }
        if(a != 0){
                long double x = (- c - b * y1) / a;
                v.push_back({{x, y1}, fabs(x1 - x)});
                x = (- c - b * y2) / a;
                g.push_back({{x, y2}, fabs(x2 - x)});
        }
        for(auto x: v){
                for(auto y: g){
                        auto a = x.fi, b = y.fi;
                        ans = min(ans, x.se + y.se + sqrt((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se)));
                }
        }
        cout << fixed << setprecision(9) << ans << "\n";
}