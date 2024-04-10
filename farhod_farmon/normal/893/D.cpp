#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 10010;
const long long mod = 1000000007;
const long long block = 500;

using namespace std;

long long n, d;
long long f;
long long a[N], t[4 * N], lz[4 * N];
vector < int > v;
set < int > s;

void push(int x)
{
        if(lz[x] == 0){
                return;
        }
        t[x * 2] += lz[x];
        lz[x * 2] += lz[x];
        t[x * 2 + 1] += lz[x];
        lz[x * 2 + 1] += lz[x];
        lz[x] = 0;
}

void upd(int x, int l, int r, int tl, int tr, long long y)
{
        if(tl > tr){
                return;
        }
        if(l == tl && r == tr){
                t[x] += y;
                lz[x] += y;
                return;
        }
        push(x);
        int m = (l + r) / 2;
        upd(x * 2, l, m, tl, min(m, tr), y);
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, y);
        t[x] = max(t[x * 2], t[x * 2 + 1]);
}

long long get(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return -1e18;
        }
        if(l == tl && r == tr){
                return t[x];
        }
        push(x);
        int m = (l + r) / 2;
        return max(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

void go(int x)
{
        s.erase(x);
        long long g = get(1, 1, n, x, n);
        upd(1, 1, n, x, n, d - g);
}

void solve()
{
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                if(a[i] == 0){
                        v.push_back(i);
                }
                s.insert(i);
                upd(1, 1, n, i, n, a[i]);
                if(get(1, 1, n, i, i) > d){
                        cout << -1 << "\n";
                        return;
                }
        }
        for(int x: v){
                if(get(1, 1, n, x, x) >= 0){
                        continue;
                }
                go(x);
                auto p = s.lower_bound(x);
                while(p != s.begin() && get(1, 1, n, x, x) < 0){
                        p--;
                        go(*p);
                        p = s.lower_bound(x);
                }
                if(get(1, 1, n, x, x) < 0){
                        cout << -1 << "\n";
                        return;
                }
        }
        cout << n - s.size() << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("mine.in");
        //fout("mine.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}