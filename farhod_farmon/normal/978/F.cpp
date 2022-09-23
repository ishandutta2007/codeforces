#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int m;
int a[N];
int ans[N];
pair < int, int > p[N];

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                p[i] = {a[i], i};
        }
        sort(p + 1, p + n + 1);
        for(int i = 1, j = 0; i <= n; i++){
                while(j + 1 < i && p[j + 1].fi < p[i].fi){
                        j++;
                }
                ans[p[i].se] = j;
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                if(a[x] > a[y]){
                        ans[x]--;
                }
                if(a[y] > a[x]){
                        ans[y]--;
                }
        }
        for(int i = 1; i <= n; i++){
                cout << ans[i] << " ";
        }
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