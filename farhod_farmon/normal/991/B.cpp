#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 50050;
const long long Q = 2e18;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int a[N];

bool good()
{
        long double c = 0;
        for(int i = 1; i <= n; i++){
                c += a[i];
        }
        return c / n >= 4.5;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        for(int i = 0; i <= n; i++){
                if(good()){
                        cout << i << "\n";
                        return;
                }
                a[i + 1] = 5;
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