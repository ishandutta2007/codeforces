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
int m;
int a[N];
int d[N];
char c[N];
set < int > s;

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= m; i++)
        {
                cin >> c[i] >> a[i];
        }
        for(int i = m; i >= 1; i--)
        {
                if(c[i] == '-') s.insert(a[i]);
                else s.erase(a[i]);
        }
        for(int i = 1; i <= m; i++)
        {
                if(c[i] == '+')
                {
                        if(!s.empty()) d[a[i]] = 1;
                        if(i > 1 && a[i] != a[i - 1]) d[a[i]] = 1;
                        s.insert(a[i]);
                }
                else
                {
                        s.erase(a[i]);
                        if(!s.empty()) d[a[i]] = 1;
                        if(i < m && a[i] != a[i + 1]) d[a[i]] = 1;
                }
        }
        vector < int > v;
        for(int i = 1; i <= n; i++)
        {
                if(d[i] == 0)v.pb(i);
        }
        cout << v.size() << endl;
        for(int x: v) cout << x << " ";
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