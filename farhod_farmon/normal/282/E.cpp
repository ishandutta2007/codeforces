#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 1000010;
const long long mod = 1000000007;
const long long block = 500;

using namespace std;

long long n;
long long g;
long long a[N];
long long t[N * 100][2];

void add(long long x)
{
        int h = 0;
        for(long long i = 44; i >= 0; i--){
                long long f = (x >> i) & 1;
                if(!t[h][f]){
                        t[h][f] = ++g;
                }
                h = t[h][f];
        }
}

long long get(long long x)
{
        int h = 0;
        long long ans = 0;
        for(int i = 44; i >= 0; i--){
                long long f = (x >> i) & 1;
                if(t[h][1 ^ f]){
                        h = t[h][1 ^ f];
                        ans += (1ll << i);
                }
                else{
                        h = t[h][f];
                }
        }
        return ans;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = n - 1; i >= 1; i--){
                a[i] ^= a[i + 1];
        }
        add(0);
        long long ans = a[1], s = 0;
        for(int i = 1; i <= n; i++){
                ans = max(ans, get(a[i]));
                s ^= a[i] ^ a[i + 1];
                add(s);
        }
        ans = max(ans, get(0));
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("park.in");
        //fout("park.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}