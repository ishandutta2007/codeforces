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
int d[N];
vector < int > v[N];

void dfs(int x, int g)
{
        d[g]++;
        for(int y: v[x]){
                dfs(y, g + 1);
        }
}

void solve()
{
        cin >> n;
        for(int i = 2; i <= n; i++){
                int x;
                cin >> x;
                v[x].push_back(i);
        }
        dfs(1, 1);
        int ans = 0;
        for(int i = 1; i < N; i++){
                ans += d[i] % 2;
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