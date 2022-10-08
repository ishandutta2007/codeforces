#include <iostream>
#include <vector>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long lld;

int grid[52][52];
int N;

char inp[52];

void Input()
{
    scanf("%d", &N);
    for (int i=1; i<=N; i++)
    {
        scanf("%s", inp);
        for (int j=1; j<=N; j++)
        {
            grid[i][j] = (inp[j-1] - '0');
        }
    }
}

int mvx[4] = {1, -1, 0, 0};
int mvy[4] = {0, 0, 1, -1};

pair<int, int> top, bottom;

bool OK(int tx, int ty, int bx, int by)
{
    tx--;
    ty--;

    bx++;
    by++;


    //cout<<tx<<", "<<ty<<", "<<bx<<", "<<by<<"\n";
    bool legit = false;

    for (int x=tx; x<=bx; x++)
    {
        for (int y=ty; y<=by; y++)
        {
            if (x<1 || x>N || y<1 || y>N) continue;

            legit = true;
            //cout<<x<<", "<<y<<" is "<<grid[x][y]<<"\n";
            if (x!=tx && y!=ty && x!=bx && y!=by)
            {
                if (grid[x][y] != 4) return false; /// Not borders
                continue;
            }

            if ((x==tx&&y==ty) ||
                (x==tx&&y==by) ||
                (x==bx&&y==ty) ||
                (x==bx&&y==by))
            {
                if (grid[x][y] != 1) return false;
                continue;
            }

            if (grid[x][y] != 2) return false;
        }
    }

    return legit;
}

int main ()
{
    //freopen("input.txt", "r", stdin);

    Input();

    int cnt = 0;

    //cout<<OK(1, 1, 1, 1)<<"\n";
    //return 0;

    for (int tx=1; tx<=N; tx++)
    {
        for (int ty=1; ty<=N; ty++)
        {
            for (int bx=tx; bx<=N; bx++)
            {
                for (int by=ty; by<=N; by++)
                {
                    bool cur = OK(tx, ty, bx, by);
                    cnt += cur;

                    if (cur)
                    {
                        top = make_pair(tx-1, ty-1);
                        bottom = make_pair(bx+1, by+1);
                    }
                }
            }
        }
    }

    if (cnt != 1)
    {
        printf("No\n");
        return 0;
    }

    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=N; j++)
        {
            if (i >= top.first && i <= bottom.first &&
                j >= top.second && j <= bottom.second) continue;

            if (grid[i][j] != 0)
            {
                //cout<<i<<", "<<j<<"\n";
                printf("No\n");
                return 0;
            }
        }
    }

    printf("Yes\n");
}