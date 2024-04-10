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

char c[55][55];
int n, m;

bool can(int x1, int y1, int x2, int y2)
{
    for(int i = x1; i <= x2; i++)
        for(int j = y1; j <= y2; j++)
            if(c[i][j] != '4')
                return false;
    for(int i = y1; i <= y2; i++){
        if(x1 - 1 >= 1 && c[x1 - 1][i] != '2')
            return false;
        if(x2 + 1 <= n && c[x2 + 1][i] != '2')
            return false;
    }
    for(int i = x1; i <= x2; i++){
        if(y1 - 1 >= 1 && c[i][y1 - 1] != '2')
            return false;
        if(y2 + 1 <= m && c[i][y2 + 1] != '2')
            return false;
    }
    if(x1 - 1 >= 1 && y1 - 1 >= 1 && c[x1 - 1][y1 - 1] != '1')
        return false;
    if(x1 - 1 >= 1 && y2 + 1 <= m && c[x1 - 1][y2 + 1] != '1')
        return false;
    if(x2 + 1 <= n && y1 - 1 >= 1 && c[x2 + 1][y1 - 1] != '1')
        return false;
    if(x2 + 1 <= n && y2 + 1 <= m && c[x2 + 1][y2 + 1] != '1')
        return false;
    x1--;
    y1--;
    x2++;
    y2++;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if((i < x1 || i > x2 || j < y1 || j > y2) && c[i][j] != '0')
                return false;
    return true;
}

int main()
{
    //fin
    //fout
    ios_base::sync_with_stdio(0);
    cin >> n;
    m = n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> c[i][j];
    int x1 = -1, x2 = -1, y1 = -1, y2 = -1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(c[i][j] == '4'){
                x1 = x2 = i;
                y1 = y2 = j;
                while(c[x1 - 1][y1] == '4')
                    x1--;
                while(c[x1][y1 - 1] == '4')
                    y1--;
                while(c[x2 + 1][y2] == '4')
                    x2++;
                while(c[x2][y2 + 1] == '4')
                    y2++;
                break;
            }
        }
        if(x1 != -1)
            break;
    }
    if(x1 != -1 && can(x1, y1, x2, y2))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}