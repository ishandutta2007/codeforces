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
int a[N];

void solve()
{
        cin >> n;
        int g = 0;
        for(int i = 1; i <= n; i++)
        {
                cin >> a[i];
                g = __gcd(g, a[i]);
                a[i] %= 2;
        }
        cout << "YES" << endl;
        if(g > 1)
        {
                cout << 0 << endl;
                return;
        }
        int cnt = 0;
        for(int i = 1; i < n; i++)
        {
                if(a[i])
                {
                        if(a[i + 1])
                        {
                                cnt += 1;
                                a[i + 1] = 0;
                        }
                        else
                        {
                                cnt += 2;
                        }
                }
        }
        cout << cnt + a[n] * 2 << endl;
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