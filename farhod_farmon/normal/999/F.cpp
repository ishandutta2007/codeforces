#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 550;
const long long Q = 100100;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int k;
int a[Q];
int b[Q];
int cost[Q];
int d[N][N * 10];

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n * k; i++){
                int x;
                cin >> x;
                a[x]++;
        }
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                b[x]++;
        }
        for(int i = 1; i <= k; i++){
                cin >> cost[i];
        }
        int ans = 0;
        for(int i = 1; i <= Q; i++){
                if(!b[i]){
                        continue;
                }
                for(int j = 1; j <= b[i]; j++){
                        for(int h = 1; h <= a[i]; h++){
                                for(int f = 1; f <= min(k, h); f++){
                                        d[j][h] = max(d[j][h], d[j - 1][h - f] + cost[f]);
                                }
                        }
                }
                ans += d[b[i]][a[i]];
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