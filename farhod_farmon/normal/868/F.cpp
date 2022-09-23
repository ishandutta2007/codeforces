#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 2e18;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

long long C;
int t[N];
int a[N];
int tl, tr;

void make(int l, int r)
{
        while(tr < r){
                tr++;
                C += t[a[tr]];
                t[a[tr]]++;
        }
        while(tl > l){
                tl--;
                C += t[a[tl]];
                t[a[tl]]++;
        }
        while(tr > r){
                t[a[tr]]--;
                C -= t[a[tr]];
                tr--;
        }
        while(tl < l){
                t[a[tl]]--;
                C -= t[a[tl]];
                tl++;
        }
}

int n;
int k;
long long d[N];
long long f[N];

void go(int l, int r, int bl, int br)
{
        if(l > r){
                return;
        }
        int m = (l + r) / 2;
        long long best = 1e18, h;
        for(int i = bl; i <= min(m, br); i++){
                make(i, m);
                if(d[i - 1] + C < best){
                        best = d[i - 1] + C;
                        h = i;
                }
        }
        f[m] = best;
        go(m + 1, r, h, br);
        go(l, m - 1, bl, h);
}

void solve()
{
        cin >> n >> k;
        tl = 1;
        tr = n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                C += t[a[i]];
                t[a[i]]++;
                d[i] = C;
        }
        for(int i = 2; i <= k; i++){
                go(1, n, 1, n);
                for(int j = 1; j <= n; j++){
                        d[j] = f[j];
                }
        }
        cout << d[n] << "\n";
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