#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 2000200;
const long long Q = N * 30;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
int m;
int q;
int f[N];
string s, t;

void solve()
{
        cin >> n >> m >> q >> s >> t;
        s = "1" + s;
        t = "1" + t;
        for(int i = n; i >= 1; i--){
                f[i] = f[i + 1];
                if(i + m - 1 <= n){
                        bool good = true;
                        for(int j = 0; j < m; j++){
                                if(s[i + j] != t[j + 1]){
                                        good = false;
                                }
                        }
                        f[i] += good;
                }
        }
        for(int i = 1; i <= q; i++){
                int l, r;
                cin >> l >> r;
                if(l + m - 1 > r){
                        cout << 0 << "\n";
                        continue;
                }
                cout << f[l] - f[r - m + 2] << "\n";
        }

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