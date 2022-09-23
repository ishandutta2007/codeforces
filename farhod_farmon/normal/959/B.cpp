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
int k;
int m;
int a[N];
int c[N];
map < string, int > f;

void solve()
{
        cin >> n >> k >> m;
        for(int i = 1; i <= n; i++){
                string s;
                cin >> s;
                f[s] = i;
        }
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= k; i++){
                int l, x = 1e9;
                cin >> l;
                vector < int > v(l);
                for(int j = 0; j < l; j++){
                        cin >> v[j];
                        x = min(x, a[v[j]]);
                }
                for(int j = 0; j < l; j++){
                        a[v[j]] = x;
                }
        }
        long long ans = 0;
        for(int i = 1; i <= m; i++){
                string s;
                cin >> s;
                ans += a[f[s]];
        }
        cout << ans << "\n";
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