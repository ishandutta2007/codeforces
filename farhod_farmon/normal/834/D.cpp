#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 35500;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int k;
int a[N];
int d[N];
int t[N];

int tl;
int tr;
int cnt;
int c[N];

void add(int x, int g)
{
        cnt += c[a[x]] == 0;
        c[a[x]] += g;
        cnt -= c[a[x]] == 0;
}

void upd(int l, int r)
{
        while(tr < r){
                add(++tr, 1);
        }
        while(tl < l){
                add(tl++, -1);
        }
        while(tl > l){
                add(--tl, 1);
        }
        while(tr > r){
                add(tr--, -1);
        }
}

void work(int l, int r, int bl, int br)
{
        if(l > r){
                return;
        }
        int best = -1, mx = 0;
        int m = (l + r) / 2;
        for(int i = min(m, br); i >= bl; i--){
                upd(i, m);
                if(d[i - 1] + cnt > mx){
                        mx = d[i - 1] + cnt;
                        best = i;
                }
        }
        t[m] = mx;
        work(l, m - 1, bl, best);
        work(m + 1, r, best, br);
}

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        c[a[1]] = tl = tr = cnt = 1;
        for(int i = 1; i <= n; i++){
                upd(1, i);
                d[i] = cnt;
        }
        for(int i = 2; i <= k; i++){
                work(1, n, 1, n);
                for(int j = 1; j <= n; j++){
                        d[j] = t[j];
                }
        }
        cout << d[n] << "\n";
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