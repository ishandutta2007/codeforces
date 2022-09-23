#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1010;
const long long MX = 1000100;
const long long MAGIC = 1000;
const long long mod = 1e9 + 9;

using namespace std;

int n;
int m;
int a[N];
int l[N];
int r[N];

void solve()
{
        cin >> n;
        int ans = 0;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                ans += a[i];
        }
        cin >> m;
        if(m == 0){
                ans = -1;
        }
        for(int i = 1; i <= m; i++){
                cin >> l[i] >> r[i];
                if(ans <= r[i]){
                        ans = max(ans, l[i]);
                        break;
                }
                if(i == m){
                        ans = -1;
                }
        }
        cout << ans << endl;
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("fcount.in");
        //fout("fcount.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}