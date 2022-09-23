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
const long long MX = 200200;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
pair < pair < int, int >, int > p[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
                cin >> p[i].fi.fi;
                p[i].se = i;
        }
        for(int i = 1; i <= n; i++)
        {
                cin >> p[i].fi.se;
        }
        sort(p + 1, p + n + 1);
        cout << n / 2 + 1 << endl;
        for(int i = 1; i + 1 <= (n - 2 + n % 2); i += 2)
        {
                if(p[i].fi.se > p[i + 1].fi.se)
                {
                        cout << p[i].se << " ";
                }
                else
                {
                        cout << p[i + 1].se << " ";
                }
        }
        if(n % 2 == 0)
        {
                cout << p[n--].se << " ";
        }
        if(n % 2 == 1)
        {
                cout << p[n--].se << " ";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("rmq.in");
        //fout("rmq.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}