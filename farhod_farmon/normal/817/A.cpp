#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long MX = 1000100;
const long long H = 1 << 17;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

void solve()
{
        int x1, y1, x2, y2, x, y;
        cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
        int a = abs(x1 - x2);
        int b = abs(y1 - y2);
        if(a % x == 0 && b % y == 0 && abs(a / x - b / y) % 2 == 0){
                cout << "YES" << endl;
        }
        else{
                cout << "NO" << endl;
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}