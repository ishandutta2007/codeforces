
#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int a[N];
pair < int, int > p[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> p[i].fi;
                p[i].se = i;
        }
        sort(a + 1, a + n + 1);
        sort(p + 1, p + n + 1);
        for(int i = 1; i <= n; i++){
                p[p[i].se].fi = a[n - i + 1];
        }
        for(int i = 1; i <= n; i++){
                cout << p[i].fi << " ";
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
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}