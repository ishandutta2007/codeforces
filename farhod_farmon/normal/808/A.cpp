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
ll p = 1;

void solve()
{
        cin >> n;
        while(p * 10 <= n){
                p *= 10;
        }
        if(n % p == 0){
                cout << p << endl;
                return;
        }
        p = 10;
        ll cnt = 0;
        while(p < n){
                while(n % p){
                        cnt += p / 10;
                        n += p / 10;
                }
                p *= 10;
        }
        cout << cnt << endl;
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