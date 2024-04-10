#include <bits/stdc++.h>

using namespace std;

int N;
char grid[3000][3000];
int x=1, y=1500;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &N);
    int a;
    int miny=1500, maxy=1500;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a);
        if(i&1)
        {
            for(int j=0; j<a; j++)
            {
                grid[x][y]='\\';
                x++;
                if(j==a-1)
                    break;
                y++;
                maxy=max(maxy, y);
            }
        }
        else
        {
            for(int j=0; j<a; j++)
            {
                grid[x][y]='/';
                x++;
                if(j==a-1)
                    break;
                y--;
                miny=min(miny, y);
            }
        }
    }
    for(int j=miny; j<=maxy; j++)
    {
        vector<char> output;
        for(int i=x-1; i>=1; i--)
        {
            if(grid[i][j])
                output.push_back(grid[i][j]);
            else
                output.push_back(' ');
        }
        for(int i=output.size()-1; i>=0; i--)
            putchar(output[i]);
        putchar('\n');
    }
    return 0;
}