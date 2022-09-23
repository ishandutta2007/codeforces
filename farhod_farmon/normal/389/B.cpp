#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 105;

using namespace std;

int n;
char c[N][N];

bool can(int x, int y)
{
    if(c[x - 1][y] != '#')
        return false;
    if(c[x][y - 1] != '#')
        return false;
    if(c[x][y + 1] != '#')
        return false;
    if(c[x + 1][y] != '#')
        return false;
    return true;
}

void cl(int x, int y)
{
    c[x][y] = c[x - 1][y] = c[x + 1][y] = c[x][y - 1] = c[x][y + 1] = '.';
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(c[i][j] == '.')
                continue;
            if(can(i, j)){
                cl(i, j);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(c[i][j] == '#'){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}