#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n, k, x;
int a[N];

void solve()
{
        cin >> n >> k >> x;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        int cnt = 0;
        for(int i = 1; i <= n - k; i++){
                cnt += a[i];
        }
        cout << cnt + k * x << "\n";
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