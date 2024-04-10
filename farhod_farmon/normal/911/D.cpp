#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1505;
const long long Q = 5000010;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int a[N];
int t[N];

void upd(int x, int g)
{
        while(x < N){
                t[x] += g;
                x += x & -x;
        }
}

int get(int x)
{
        int cnt = 0;
        while(x > 0){
                cnt += t[x];
                x -= x & -x;
        }
        return cnt;
}

int f(int l, int r)
{
        int cnt = 0;
        for(int i = r; i >= l; i--){
                cnt += get(a[i]);
                upd(a[i], 1);
        }
        for(int i = r; i >= l; i--){
                upd(a[i], -1);
        }
        return cnt;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        int cnt = f(1, n), m;
        cin >> m;
        for(int i = 1; i <= m; i++){
                int l, r;
                cin >> l >> r;
                int c = (r - l + 1);
                cnt = (cnt + c * (c - 1) / 2) % 2;
                if(cnt % 2){
                        cout << "odd\n";
                }
                else{
                        cout << "even\n";
                }
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("bootfall.in");
        //fout("bootfall.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}