#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 7;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

long long k, t, d, g, ans, o;

void solve()
{
        cin >> k >> d >> t;
        k += k; d += d; t += t;
        g = ((k - 1) / d + 1) * d;
        o = k + (g - k) / 2;
        ans += (t / o) * g;
        t %= o;
        if(t <= k){
                ans += t;
        }
        else{
                ans += k + (t - k) * 2;
        }
        cout << ans / 2 << "." << (ans % 2) * 5 << "\n";
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