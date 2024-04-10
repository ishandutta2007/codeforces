#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 303;

using namespace std;

int p[N][N];
int a[N][N];
int ans[N];
int n;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n + 1; i++){
        for(int j = 1; j <= n; j++){
            int x;
            cin >> a[i][j];
            x = a[i][j];
            p[i][x] = j;
        }
    }
    vector < int > v;
    for(int i = 1; i <= n; i++){
        v.pb(p[n + 1][i]);
        sort(v.begin(), v.end());
        for(int j = 1; j <= n; j++){
            int x = v[0];
            x = a[n + 1][x];
            if(x == j){
                if(v.size() == 1)
                    continue;
                x = v[1];
                x = a[n + 1][x];
            }
            if(ans[j] == 0 || p[j][x] < p[j][ans[j]])
                ans[j] = x;
        }
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}