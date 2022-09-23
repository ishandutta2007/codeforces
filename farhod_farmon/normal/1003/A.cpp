#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200100;
const long long Q = N * 30;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int c[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                c[x] = c[x] + 1;
        }
        int cnt = 0;
        for(int i = 1; i < N; i++){
                cnt = max(cnt, c[i]);
        }
        cout << cnt << "\n";
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