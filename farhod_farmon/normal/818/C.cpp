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
const long long MX = 1000010;
const long long H = 17;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int q, n, m;
int d1[N];
int d2[N];
int d3[N];
int d4[N];
int a[N];
int b[N];
int c[N];
int d[N];

void solve()
{
        int c1, c2, c3, c4;
        cin >> q >> n >> m;
        for(int i = 1; i <= q; i++){
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                d1[min(x1, x2)]++;
                d2[max(x1, x2)]++;
                d3[min(y1, y2)]++;
                d4[max(y1, y2)]++;
                a[i] = x1;
                b[i] = y1;
                c[i] = x2;
                d[i] = y2;
        }
        for(int i = 1; i <= n; i++) d1[i] += d1[i - 1];
        for(int i = n; i >= 1; i--) d2[i] += d2[i + 1];
        for(int i = 1; i <= m; i++) d3[i] += d3[i - 1];
        for(int i = m; i >= 1; i--) d4[i] += d4[i + 1];
        cin >> c1 >> c2 >> c3 >> c4;
        for(int i = 1; i <= q; i++){
                int x1 = a[i], y1 = b[i], x2 = c[i], y2 = d[i];
                if(d1[min(x1, x2) - (x1 == x2)] - (x1 != x2) != c1) continue;
                if(d2[max(x1, x2) + (x1 == x2)] - (x1 != x2) != c2) continue;
                if(d3[min(y1, y2) - (y1 == y2)] - (y1 != y2) != c3) continue;
                if(d4[max(y1, y2) + (y1 == y2)] - (y1 != y2) != c4) continue;
                cout << i << "\n";
                return;
        }
        cout << -1 << "\n";
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
                sc("%d", &TE);
        while(TE--)
                solve();
        return 0;
}