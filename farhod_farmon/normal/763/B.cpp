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
const long long MX = 300300;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;

void solve()
{
        cin >> n;
        cout << "YES\n";
        for(int i = 1; i <= n; i++)
        {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                cout << (x1 & 1) + (y1 &1) * 2 + 1 << endl;
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("friendcross.in");
        //fout("friendcross.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}