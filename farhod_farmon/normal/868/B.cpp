#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 110;
const long long Q = 2e18;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int h, m, s, t1, t2, o = 12 * 60 * 60;

bool go(int x, int y)
{
        while(x != y){
                if(x == h || x == m || x == s){
                        break;
                }
                x = (x + 1) % o;
        }
        return x == y;
}

void solve()
{
        cin >> h >> m >> s >> t1 >> t2;
        t1 %= 12; t2 %= 12; h %= 12;
        h = h * 60 * 60 + m * 60 + s;
        m = m * 60 + s;
        h = o * h / (12 * 60 * 60);
        m = o * m / (60 * 60);
        s = o * s / (60);
        t1 *= 3600;
        t2 *= 3600;
        if(go(t1, t2) || go(t2, t1)){
                cout << "YES" << "\n";
        }
        else{
                cout << "NO" << "\n";
        }
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