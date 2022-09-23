#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 200200;
const long long mod = 998244353;
const long long MAGIC = sqrt(N);

using namespace std;

int n;
int a[N];

void solve()
{
        int ans = 0, cnt = 0;
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                if(a[i - 1] * 2 >= a[i]){
                        cnt++;
                }
                else{
                        cnt = 1;
                }
                ans = max(ans, cnt);
        }
        cout << ans << "\n";
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