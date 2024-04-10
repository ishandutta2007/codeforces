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

ll n;
int ans = 1e9;
ll a[N];
bool used[N];

void rec(ll h, ll w, ll nh, ll nw, int i)
{
        if(h >= nh && w >= nw){
                ans = min(ans, i - 1);
                return;
        }
        if(i == n + 1){
                return;
        }
        if(a[i] == 2){
                while(h < nh){
                        h *= 2;
                        i++;
                }
                while(w < nw){
                        w *= 2;
                        i++;
                }
                ans = min(ans, i - 1);
                return;
        }
        if(h < nh){
                rec(h * a[i], w, nh, nw, i + 1);
        }
        if(w < nw){
                rec(h, w * a[i], nh, nw, i + 1);
        }
}

void solve()
{
        ll aa, bb, h, w;
        cin >> aa >> bb >> h >> w >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        reverse(a + 1, a + n + 1);
        rec(h, w, aa, bb, 1);
        rec(h, w, bb, aa, 1);
        if(ans >= n + 1){
                ans = -1;
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