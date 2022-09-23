#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

int n, m[101], a[101][101];
bool used[101];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> m[i];
        for(int j = 1; j <= m[i]; j++)
            cin >> a[i][j];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m[i]; j++)
            used[a[i][j]] = true;
        bool can = true;
        for(int h = 1; h <= n; h++){
            if(h == i)
                continue;
            int cnt = 0;
            for(int j = 1; j <= m[h]; j++)
                cnt += used[a[h][j]];
            if(cnt == m[h])
                can = false;
        }
        if(can)
            cout << "YES\n";
        else
            cout << "NO\n";
        for(int j = 1; j <= m[i]; j++)
            used[a[i][j]] = false;
    }
}