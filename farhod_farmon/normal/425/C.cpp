#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

int n;
int m;
int s;
int e;
int a[N];
int b[N];
int d[N][330];
vector < int > v[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> s >> e;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++){
        cin >> b[i];
        v[b[i]].push_back(i);
    }
    for(int i = 1; i < N; i++){
        v[i].push_back(m + 1);
        for(int j = 1; j <= 300; j++)
            d[i][j] = m + 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int h = 0;
        for(int j = 0; j <= 300; j++){
            d[i + 1][j] = min(d[i + 1][j], d[i][j]);
            while(h + 1 < v[a[i]].size() && v[a[i]][h] <= d[i][j])
                h++;
            d[i + 1][j + 1] = min(d[i + 1][j + 1], v[a[i]][h]);
            if(v[a[i]][h] <= m && (j + 1) * e + i + v[a[i]][h] <= s)
                ans = max(ans, j + 1);
        }
    }
    cout << ans << endl;
}