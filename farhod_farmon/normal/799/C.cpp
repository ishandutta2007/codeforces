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
const long long MX = 30030;
const long long MAGIC = 30;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int c;
int d;
int a[N];
int b[N];

void upda(int x, int g)
{
        while(x < N){
                a[x] = max(a[x], g);
                x += x & -x;
        }
}

void updb(int x, int g)
{
        while(x < N){
                b[x] = max(b[x], g);
                x += x & -x;
        }
}

int geta(int x)
{
        int mx = 0;
        while(x){
                mx = max(mx, a[x]);
                x -= x & -x;
        }
        return mx;
}

int getb(int x)
{
        int mx = 0;
        while(x){
                mx = max(mx, b[x]);
                x -= x & -x;
        }
        return mx;
}

void solve()
{
        cin >> n >> c >> d;
        int ans = 0;
        for(int i = 1; i <= n; i++){
                int x, y;
                char cc;
                cin >> x >> y >> cc;
                if(cc == 'C'){
                        if(c >= y){
                                int mx = max(geta(c - y), getb(d));
                                if(mx){
                                        ans = max(ans, x + mx);
                                }
                        }
                        upda(y, x);
                }
                else{
                        if(d >= y){
                                int mx = max(geta(c), getb(d - y));
                                if(mx){
                                        ans = max(ans, x + mx);
                                }
                        }
                        updb(y, x);
                }
        }
        cout << ans << endl;
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