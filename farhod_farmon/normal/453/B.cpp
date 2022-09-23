#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 110;
const long long MX = 1000100;
const long long H = 17;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int f[N];
int d[N][1 << H];
int p[N][1 << H];

void solve()
{
        vector < int > v;
        for(int i = 2; i < 60; i++){
                bool f = true;
                for(int j = 2; j < i; j++){
                        if(i % j == 0){
                                f = false;
                        }
                }
                if(f){
                        v.pb(i);
                }
        }
        for(int i = 1; i < 60; i++){
                for(int j = 0; j < H; j++){
                        if(i % v[j] == 0){
                                f[i] |= (1 << j);
                        }
                }
        }
        cin >> n;
        for(int i = 1; i <= n; i++){
                for(int j = 0; j < (1 << H); j++){
                        d[i][j] = 1e9;
                }
        }
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                for(int j = (1 << H) - 1; j >= 0; j--){
                        for(int h = 1; h < 60; h++){
                                if(f[h] & j){
                                        continue;
                                }
                                int nj = f[h] | j;
                                if(d[i][nj] > d[i - 1][j] + abs(x - h)){
                                        d[i][nj] = d[i - 1][j] + abs(x - h);
                                        p[i][nj] = h;
                                }
                        }
                }
        }
        int best = 0;
        for(int j = 0; j < (1 << H); j++){
                if(d[n][j] < d[n][best]){
                        best = j;
                }
        }
        vector < int > ans;
        for(int i = n; i >= 1; i--){
                ans.pb(p[i][best]);
                best ^= f[p[i][best]];
        }
        for(int i = ans.size() - 1; i >= 0; i--){
                cout << ans[i] << " ";
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