#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long MX = 5050;
const long long MAGIC = 30;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int l[N];
int r[N];

void solve()
{
        cin >> n;
        l[0] = -1e9;
        for(int i = 1; i <= n; i++)
        {
                cin >> a[i];
                l[i] = l[i - 1];
                if(!a[i])
                {
                        l[i] = i;
                }
        }
        r[n + 1] = 1e9;
        for(int i = n; i >= 1; i--)
        {
                r[i] = r[i + 1];
                if(!a[i])
                {
                        r[i] = i;
                }
        }
        for(int i = 1; i <= n; i++)
        {
                cout << min(i - l[i], r[i] - i) << " \n"[i == n];
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("unionday.in");
        //fout("unionday.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}