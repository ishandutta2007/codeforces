#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const long long mod = 998244353;

using namespace std;

int n;
int x[N];
int y[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> x[i] >> y[i];
        }
        set < pair < int, pair < int, int > > > s;
        for(int i = 1; i <= n; i++){
                for(int j = i + 1; j <= n; j++){
                        int a = y[i] - y[j], b = x[i] - x[j], c = y[i] * x[j] - y[j] * x[i];
                        int g = __gcd(__gcd(abs(a), abs(b)), abs(c));
                        a /= g;
                        b /= g;
                        c /= g;
                        if(a < 0 || a == 0 && b < 0){
                                c *= -1;
                                a *= -1;
                                b *= -1;
                        }
                        s.insert({c, {a, b}});
                }
        }
        long long res = 1ll * s.size() * (s.size() - 1) / 2;
        map < pair < int, int >, int > d;
        for(auto p: s){
                d[p.se] += 1;
        }
        for(auto p: d){
                res -= 1ll * p.se * (p.se - 1) / 2;
        }
        cout << res << "\n";
}