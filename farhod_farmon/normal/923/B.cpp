#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
long long a[N];
long long b[N];
set < pair < long long, int > > s;

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> b[i];
        }
        long long cr = 0;
        for(int i = 1; i <= n; i++){
                s.insert({a[i] + cr, i});
                long long ans = 1ll * s.size() * b[i];
                while(!s.empty() && s.begin()->fi - cr < b[i]){
                        ans -= b[i] - s.begin()->fi + cr;
                        s.erase(s.begin());
                }
                cr += b[i];
                cout << ans << " ";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}