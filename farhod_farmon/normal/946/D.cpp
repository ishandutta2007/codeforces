#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 550;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int m;
int k;
int best[N];
int d[N][N];
char c[N][N];

void solve()
{
        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++){
                vector < int > v;
                for(int j = 1; j <= m; j++){
                        cin >> c[i][j];
                        if(c[i][j] == '1'){
                                v.push_back(j);
                        }
                }
                for(int j = 0; j <= k; j++){
                        d[i][j] = d[i - 1][j];
                        if(!v.empty()){
                                d[i][j] += v.back() - v[0] + 1;
                        }
                        best[j] = 1e9;
                }
                int l = v.size();
                for(int j = 0; j < v.size(); j++){
                        for(int h = j; h < v.size(); h++){
                                best[l - (h - j + 1)] = min(best[l - (h - j + 1)], v[h] - v[j] + 1);
                        }
                }
                best[v.size()] = 0;
                for(int j = 1; j <= k; j++){
                        for(int h = 1; h <= j; h++){
                                d[i][j] = min(d[i][j], d[i - 1][j - h] + best[h]);
                        }
                }
        }
        int ans = 1e9;
        for(int i = 0; i <= k; i++){
                ans = min(ans, d[n][i]);
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