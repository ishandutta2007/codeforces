#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
bool used[N + N];

void solve()
{
        cin >> n;
        int ans = 0;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                if(x){
                        ans += 1 - used[x + N];
                        used[x + N] = 1;
                }
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}