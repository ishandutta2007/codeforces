#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 22;

using namespace std;

int n, m;
int a[N][N];

bool can(int x, int y)
{
    int b[N][N];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            b[i][j] = a[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
        swap(b[i][x], b[i][y]);
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= m; j++){
            while(b[i][j] != j){
                swap(b[i][j], b[i][b[i][j]]);
                cnt++;
            }
        }
        if(cnt > 1)
            return false;
    }
    return true;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    bool ans = can(1, 1);
    for(int i = 1; i <= m; i++){
        for(int j = i + 1; j <= m; j++){
            ans |= can(i, j);
        }
    }
    if(ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}