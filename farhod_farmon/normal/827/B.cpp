#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200010;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
int cnt;
int d[N];

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= k; i++){
                d[i - 1]++;
                cnt++;
        }
        for(int i = 2; i <= n; i++){
                if(i + k <= n){
                        d[(i - 2) % k]++;
                        cnt++;
                }
        }
        cout << d[0] + d[1] << "\n";
        assert(cnt == n - 1);
        for(int i = 1; i <= k; i++){
                cout << 1 << " " << i + 1 << "\n";
        }
        for(int i = 2; i <= n; i++){
                if(i + k <= n){
                        cout << i << " " << i + k << "\n";
                }
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