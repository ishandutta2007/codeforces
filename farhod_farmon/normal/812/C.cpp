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
const long long MX = 10010;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

ll n;
ll S;
ll a[N];

ll f(ll k)
{
        vector < ll > v;
        for(int i = 1; i <= n; i++){
                v.pb(a[i] + i * k);
        }
        sort(v.begin(), v.end());
        ll cnt = 0;
        for(int i = 0; i < k; i++){
                cnt += v[i];
        }
        return cnt;
}

void solve()
{
        cin >> n >> S;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        int l = 0, r = n;
        while(l < r){
                int m = (l + r) / 2;
                if(f(m + 1) <= S){
                        l = m + 1;
                }
                else{
                        r = m;
                }
        }
        cout << l << " " << f(l) << endl;
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("curling.in");
        //fout("curling.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}