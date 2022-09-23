#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long Q = 200200;
const long long mod = 998244353;
const long long MAGIC = sqrt(N);

using namespace std;

int n;
long long k;
long long a[N];
map < int, int > d[12];

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                long long x = a[i] % k;
                for(int j = 1; j < 11; j++){
                        x = x * 10 % k;
                        d[j][x]++;
                }
        }
        long long ans = 0;
        for(int i = 1; i <= n; i++){
                long long g = 0, x = a[i];
                while(x > 0){
                        g++;
                        x /= 10;
                }
                x = a[i] % k;
                if(d[g].find((k - x) % k) != d[g].end()){
                        ans += d[g][(k - x) % k];
                }
                for(int j = 0; j < g; j++){
                        x = x * 10 % k;
                }
                x = (x + a[i]) % k;
                ans -= (x == 0);
        }
        cout << ans << "\n";
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