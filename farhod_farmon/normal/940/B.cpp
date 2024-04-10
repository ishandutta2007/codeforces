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

long long n, k, a, b;

void solve()
{
        cin >> n >> k >> a >> b;
        long long ans = 0;
        if(k == 1){
                cout << (n - 1) * a << "\n";
                return;
        }
        while(n > 0){
                if(n % k == 0){
                        long long g = n / k;
                        ans += min(b, (n - g) * a);
                        n /= k;
                }
                else{
                        ans += a * (n % k);
                        n -= n % k;
                }
        }
        cout << ans - a << "\n";
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