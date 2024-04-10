#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

int n, m, d[1001][1001][4];
char c[1001][1001];
set < pair < int, pair < pair < int, int >, int > > > s;

void update(int x, int y, int h, int g)
{
    s.erase({d[x][y][h], {{x, y}, h}});
    d[x][y][h] = g;
    s.insert({d[x][y][h], {{x, y}, h}});
}

bool canR(int x, int y, int h)
{
    if(x < 1 || y < 1 || x > n || y > m || c[x][y] == '*')
        return false;
    if(c[x][y] == '+')
        return true;
    if(c[x][y] == '-' && h % 2 == 0)
        return true;
    if(c[x][y] == '|' && h % 2 == 1)
        return true;
    if(c[x][y] == '>' && h == 0)
        return true;
    if(c[x][y] == '^' && h == 1)
        return true;
    if(c[x][y] == '<' && h == 2)
        return true;
    if(c[x][y] == 'v' && h == 3)
        return true;
    if(c[x][y] == 'R' && h != 0)
        return true;
    if(c[x][y] == 'D' && h != 3)
        return true;
    if(c[x][y] == 'L' && h != 2)
        return true;
    if(c[x][y] == 'U' && h != 1)
        return true;
    return false;
}

bool canL(int x, int y, int h)
{
    if(x < 1 || y < 1 || x > n || y > m || c[x][y] == '*')
        return false;
    if(c[x][y] == '+')
        return true;
    if(c[x][y] == '-' && h % 2 == 0)
        return true;
    if(c[x][y] == '|' && h % 2 == 1)
        return true;
    if(c[x][y] == '<' && h == 0)
        return true;
    if(c[x][y] == 'v' && h == 1)
        return true;
    if(c[x][y] == '>' && h == 2)
        return true;
    if(c[x][y] == '^' && h == 3)
        return true;
    if(c[x][y] == 'R' && h != 2)
        return true;
    if(c[x][y] == 'D' && h != 1)
        return true;
    if(c[x][y] == 'L' && h != 0)
        return true;
    if(c[x][y] == 'U' && h != 3)
        return true;
    return false;
}

bool canD(int x, int y, int h)
{
    if(x < 1 || y < 1 || x > n || y > m || c[x][y] == '*')
        return false;
    if(c[x][y] == '+')
        return true;
    if(c[x][y] == '-' && h % 2 == 1)
        return true;
    if(c[x][y] == '|' && h % 2 == 0)
        return true;
    if(c[x][y] == 'v' && h == 0)
        return true;
    if(c[x][y] == '>' && h == 1)
        return true;
    if(c[x][y] == '^' && h == 2)
        return true;
    if(c[x][y] == '<' && h == 3)
        return true;
    if(c[x][y] == 'R' && h != 1)
        return true;
    if(c[x][y] == 'D' && h != 0)
        return true;
    if(c[x][y] == 'L' && h != 3)
        return true;
    if(c[x][y] == 'U' && h != 2)
        return true;
    return false;
}

bool canU(int x, int y, int h)
{
    if(x < 1 || y < 1 || x > n || y > m || c[x][y] == '*')
        return false;
    if(c[x][y] == '+')
        return true;
    if(c[x][y] == '-' && h % 2 == 1)
        return true;
    if(c[x][y] == '|' && h % 2 == 0)
        return true;
    if(c[x][y] == '^' && h == 0)
        return true;
    if(c[x][y] == '<' && h == 1)
        return true;
    if(c[x][y] == 'v' && h == 2)
        return true;
    if(c[x][y] == '>' && h == 3)
        return true;
    if(c[x][y] == 'R' && h != 3)
        return true;
    if(c[x][y] == 'D' && h != 2)
        return true;
    if(c[x][y] == 'L' && h != 1)
        return true;
    if(c[x][y] == 'U' && h != 0)
        return true;
    return false;
}

int main()
{
    //fin
    //fout
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> c[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            for(int h = 0; h < 4; h++)
                d[i][j][h] = 1e9;
    int xs, ys, xf, yf;
    cin >> xs >> ys >> xf >> yf;
    d[xs][ys][0] = 0;
    s.insert({0, {{xs, ys}, 0}});
    while(!s.empty()){
        auto it = s.begin();
        int x = it->se.fi.fi;
        int y = it->se.fi.se;
        int h = it->se.se;
        s.erase(it);
        //cout << x << " " << y << " " << h << endl;
        if(d[x][y][h] + 1 < d[x][y][(h + 1) % 4])
            update(x, y, (h + 1) % 4, d[x][y][h] + 1);
        if(canR(x, y, h) && canL(x, y + 1, h) && d[x][y][h] + 1 < d[x][y + 1][h])
            update(x, y + 1, h, d[x][y][h] + 1);
        if(canL(x, y, h) && canR(x, y - 1, h) && d[x][y][h] + 1 < d[x][y - 1][h])
            update(x, y - 1, h, d[x][y][h] + 1);
        if(canD(x, y, h) && canU(x + 1, y, h) && d[x][y][h] + 1 < d[x + 1][y][h])
            update(x + 1 , y, h, d[x][y][h] + 1);
        if(canU(x, y, h) && canD(x - 1, y, h) && d[x][y][h] + 1 < d[x - 1][y][h])
            update(x - 1, y, h, d[x][y][h] + 1);
    }
    int ans = 1e9;
    for(int i = 0; i < 4; i++)
        ans = min(ans, d[xf][yf][i]);
    if(ans == 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;
}