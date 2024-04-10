#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 1000010;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

long long n;
long long c[N];
vector < long long > a, b;

long long f(long long x)
{
        if(x == 0){
                return 2;
        }
        return 1;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
        }
        sort(c + 1, c + n + 1);
        long long g = 0;
        for(int i = 1; i <= n; i++){
                while((g + 1) * (g + 1) <= c[i]){
                        g++;
                }
                if(g * g == c[i]){
                        b.push_back(f(c[i]));
                }
                else{
                        a.push_back(min(c[i] - g * g, (g + 1) * (g + 1) - c[i]));
                }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long long ans = 0;
        if(b.size() > n / 2){
                for(int i = 0; i < (int)b.size() - n / 2; i++){
                        ans += b[i];
                }
        }
        if(a.size() > n / 2){
                for(int i = 0; i < (int)a.size() - n / 2; i++){
                        ans += a[i];
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