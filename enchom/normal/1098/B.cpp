
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int n,m;
vector<char> grid[300111];
vector<char> ans[300111];

char inp[300111];
char let[] = {'A','G','C','T'};

int posx[] = {1, 1, 2, 2};
int posy[] = {1, 2, 1, 2};

int suffix[300111][4][4];

int toNum(char lt)
{
    int i;

    for (i=0;i<4;i++)
    {
        if (let[i] == lt)
            return i;
    }
}

int tryAltRow(int row,int v1,int v2)
{
    int i;
    int score = 0;

    for (i=1;i<=m;i++)
    {
        if (i%2 == 1)
        {
            if (grid[row][i] == let[v1])
                score++;
        }
        else
        {
            if (grid[row][i] == let[v2])
                score++;
        }
    }

    return score;
}

int tryAltCol(int col,int v1,int v2)
{
    int i;
    int score = 0;

    for (i=1;i<=n;i++)
    {
        if (i%2 == 1)
        {
            if (grid[i][col] == let[v1])
                score++;
        }
        else
        {
            if (grid[i][col] == let[v2])
                score++;
        }
    }

    return score;
}

pair<int,int> getOthers(int a,int b)
{
    pair<int,int> bla = make_pair(-1, -1);
    int i;

    for (i=0;i<4;i++)
    {
        if (i == a || i == b)
            continue;

        if (bla.first == -1)
            bla.first = i;
        else
            bla.second = i;
    }

    return bla;
}

int MAX(int a,int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int bestbr;
int bestx[4];
int maxscore = -1;

void tryAnswer(int x1,int x2,int x3,int x4,int br,int sc)
{
    if (sc > maxscore)
    {
        maxscore = sc;

        //cout<<"SET "<<let[x1]<<","<<let[x2]<<","<<let[x3]<<","<<let[x4]<<endl;
        //cout<<"(score="<<sc<<")"<<endl;

        bestx[0] = x1;
        bestx[1] = x2;
        bestx[2] = x3;
        bestx[3] = x4;
        bestbr = br;
    }
}

int main()
{
    int i,j,in,ja,i1,j1;

    scanf("%d %d",&n,&m);

    for (i=1;i<=n;i++)
    {
        scanf("%s",inp+1);

        grid[i].resize(m+1);
        ans[i].resize(m+1);

        for (j=1;j<=m;j++)
        {
            grid[i][j] = inp[j];
        }
    }

    for (i=m;i>=1;i--)
    {
        for (j=0;j<4;j++)
        {
            for (in=j+1;in<4;in++)
            {
                int v1 = tryAltCol(i, j, in);
                int v2 = tryAltCol(i, in, j);

                if (v2 > v1)
                    v1 = v2;

                pair<int,int> othertwo = getOthers(j, in);
                suffix[i][j][in] = suffix[i+1][othertwo.first][othertwo.second] + v1;
                suffix[i][in][j] = suffix[i][j][in];
            }
        }
    }

    int cscore;
    int newscore;
    for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
        {
            for (in=0;in<4;in++)
            {
                for (ja=0;ja<4;ja++)
                {
                    if (i == j || j == in || i == in)
                        continue;
                    if (i == ja || in == ja || j == ja)
                        continue;

                    int r,c;

                    cscore = 0;
                    for (c=1;c<=m;c++)
                    {
                        if (c >= 2)
                        {
                            if (c%2 == 0) ///ja
                            {
                                newscore = tryAltCol(c, ja, j) + suffix[c+1][i][in];
                            }
                            else ///in
                            {
                                newscore = tryAltCol(c, in, i) + suffix[c+1][j][ja];
                            }
                            //cout<<"here?"<<endl;
                            tryAnswer(i, j, in, ja, c, cscore + newscore);
                        }

                        for (r=1;r<=n;r++)
                        {
                            char thing;
                            if (c%2 == 1 && r%2 == 1)
                                thing = let[i];
                            else if (r%2 == 1 && c%2 == 0)
                                thing = let[j];
                            else if (r%2 == 0 && c%2 == 1)
                                thing = let[in];
                            else
                                thing = let[ja];

                            if (grid[r][c] == thing)
                                cscore++;
                        }
                    }
                }
            }
        }
    }

    for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
        {
            for (in=0;in<4;in++)
            {
                for (ja=0;ja<4;ja++)
                {
                    if (i == j || i == in || i == ja || j == ja || j == in || ja == in)
                        continue;

                    int r;

                    cscore = 0;
                    for (r=1;r<=n;r++)
                    {
                        if (r%2 == 1)
                            cscore += MAX(tryAltRow(r, i, j), tryAltRow(r, j, i));
                        else
                            cscore += MAX(tryAltRow(r, in, ja), tryAltRow(r, ja, in));
                    }

                    //cout<<cscore<<" for "<<let[i]<<","<<let[j]<<","<<let[in]<<","<<let[ja]<<endl;
                    tryAnswer(i, j, in, ja, m+1, cscore);
                }
            }
        }
    }

    /*cout<<"optimal = "<<maxscore<<endl;
    for (i=0;i<4;i++)
    {
        cout<<let[ bestx[i] ]<<endl;
    }
    cout<<tryAltRow(1,bestx[0],bestx[1])<<" and "<<tryAltRow(1,bestx[1],bestx[0])<<endl;*/

    if (bestbr <= m)
    {
        int i,j;

        for (i=1;i<=n;i++)
        {
            for (j=1;j<bestbr;j++)
            {
                if (i%2==1 && j%2==1)
                    ans[i][j] = let[ bestx[0] ];
                else if (i%2==1 && j%2==0)
                    ans[i][j] = let[ bestx[1] ];
                else if (i%2==0 && j%2==1)
                    ans[i][j] = let[ bestx[2] ];
                else
                    ans[i][j] = let[ bestx[3] ];
            }
        }

        char f, s;

        if (bestbr%2 == 1)
        {
            f = let[ bestx[2] ];
            s = let[ bestx[0] ];
        }
        else
        {
            f = let[ bestx[3] ];
            s = let[ bestx[1] ];
        }

        for (i=1;i<=n;i++)
        {
            if (i%2 == 1)
                ans[i][bestbr] = f;
            else
                ans[i][bestbr] = s;
        }

        for (i=bestbr + 1;i<=m;i++)
        {
            if (i%2 == 1)
            {
                if (tryAltCol(i, bestx[0], bestx[2]) >= tryAltCol(i, bestx[2], bestx[0]))
                {
                    f = let[ bestx[0] ];
                    s = let[ bestx[2] ];
                }
                else
                {
                    f = let[ bestx[2] ];
                    s = let[ bestx[0] ];
                }
            }
            else
            {
                if (tryAltCol(i, bestx[1], bestx[3]) >= tryAltCol(i, bestx[3], bestx[1]))
                {
                    f = let[ bestx[1] ];
                    s = let[ bestx[3] ];
                }
                else
                {
                    f = let[ bestx[3] ];
                    s = let[ bestx[1] ];
                }
            }

            for (j=1;j<=n;j++)
            {
                if (j%2 == 1)
                    ans[j][i] = f;
                else
                    ans[j][i] = s;
            }
        }
    }
    else
    {
        for (i=1;i<=n;i++)
        {
            char f,s;

            if (i%2 == 1)
            {
                if (tryAltRow(i, bestx[0], bestx[1]) >= tryAltRow(i, bestx[1], bestx[0]))
                {
                    f = let[ bestx[0] ];
                    s = let[ bestx[1] ];
                }
                else
                {
                    f = let[ bestx[1] ];
                    s = let[ bestx[0] ];
                }
            }
            else
            {
                if (tryAltRow(i, bestx[2], bestx[3]) >= tryAltRow(i, bestx[3], bestx[2]))
                {
                    f = let[ bestx[2] ];
                    s = let[ bestx[3] ];
                }
                else
                {
                    f = let[ bestx[3] ];
                    s = let[ bestx[2] ];
                }
            }

            for (j=1;j<=m;j++)
            {
                if (j%2 == 1)
                    ans[i][j] = f;
                else
                    ans[i][j] = s;
            }
        }
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
}