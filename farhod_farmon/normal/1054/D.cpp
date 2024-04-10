#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 10001;
const long long mod = 998244353;
const long long block = sqrt(N);

using namespace std;

int n;
long long k;
long long a[N];

void solve()
{
        cin >> n >> k;
        long long msk = (1ll << k) - 1;
        for(int i = 1; i <= n; i++){
                long long x;
                cin >> x;
                a[i] = a[i - 1] ^ x;
        }
        for(int i = 1; i <= n; i++){
                a[i] = min(a[i], a[i] ^ msk);
        }
        sort(a + 1, a + n + 1);
        long long ans = 0, cnt = 1;
        for(int i = 1; i <= n; i++){
                if(i + 1 <= n && a[i] == a[i + 1]){
                        cnt++;
                        continue;
                }
                long long x = cnt / 2, y = cnt - x;
                ans += x * (x - 1) / 2 + y * (y - 1) / 2;
                if(a[i] == 0){
                        ans += x;
                }
                cnt = 1;
        }
        cout << 1ll * n * (n + 1) / 2 - ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("distance.in");
        //fout("distance.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}