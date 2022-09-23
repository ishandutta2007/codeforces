#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100010;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

long long a, b, h, d, c, n;

void solve()
{
        cin >> a >> b >> h >> d >> c >> n;
        a = a * 60 + b;
        long long f1 = ((h - 1) / n + 1) * c;
        if(a < 20 * 60){
                h += (20 * 60 - a) * d;
        }
        long long f2 = ((h - 1) / n + 1) * c;
        if(f1 * 5 < f2 * 4){
                cout << f1 << "\n";
        }
        else{
                cout << 1.0 * f2 * 4.0 / 5.0 << "\n";
        }
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