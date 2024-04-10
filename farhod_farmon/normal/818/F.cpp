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

int q;
ll n;

bool can(ll m)
{
        if((m + 1) / 2 > n - 1){
                return false;
        }
        ll mo = (m + 1) / 2, cnt = n - mo;
        return cnt * (cnt - 1) / 2 + mo >= m;
}

void solve()
{
        cin >> q;
        while(q--){
                cin >> n;
                ll l = 0, r = n * 2;
                while(l < r){
                        ll m = (l + r) / 2;
                        if(can(m + 1)){
                                l = m + 1;
                        }
                        else{
                                r = m;
                        }
                }
                cout << l << "\n";
        }
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