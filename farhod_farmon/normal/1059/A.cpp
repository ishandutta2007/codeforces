#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 10001;
const long long mod = 1e9 + 7;;
const long long block = sqrt(N);

using namespace std;

int n;
int l;
int k;
int a[N];
int b[N];

void solve()
{
        cin >> n >> l >> k;
        a[n + 1] = l;
        for(int i = 1; i <= n; i++){
                cin >> a[i] >> b[i];
        }
        int ans = 0;
        for(int i = 0; i <= n; i++){
                ans += (a[i + 1] - a[i] - b[i]) / k;
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