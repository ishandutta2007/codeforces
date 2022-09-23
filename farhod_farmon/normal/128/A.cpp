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

char c[10][10];
bool used[10][10][111];
bool ans = false;

void dfs(int x, int y, int g)
{
    if(used[x][y][g] || x < 1 || y < 1 || x > 8 || y > 8 || g > 100)
        return;
    if(x - g > 0 && c[x - g][y] == 'S')
        return;
    used[x][y][g] = true;
    if(c[x][y] == 'A')
        ans = true;
    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++)
            if(!(x - g + i > 0 && c[x - g + i][y + j] == 'S'))
                dfs(x + i, y + j, g + 1);
}

int main()
{
	//fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    for(int i = 1; i <= 8; i++)
        for(int j = 1; j <= 8; j++)
            cin >> c[i][j];
    dfs(8, 1, 0);
    if(ans)
        cout << "WIN\n";
    else
        cout << "LOSE\n";
}