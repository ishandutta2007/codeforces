#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;
typedef int Int;

struct cell
{
    Int x,y;
};
struct t
{
    Int x,y,dist;
};

bool picture[1602][1602];
bool newpicture[1602][1602];
bool marked[1602][1602];
bool TFO[1602][1602];
bool newTFO[1602][1602];
vector<Int> suns;

bool toprint[1602][1602];

cell comp[3000001];
Int cL=0;

Int tL;
t tail[3000001];
Int h,w;

void DFS(Int x,Int y)
{
    if (x<1 || x>h || y<1 || y>w)
    return;
    if (TFO[x][y])
    return;
    if (picture[x][y]==0)
    return;

    cL++;
    comp[cL].x=x;
    comp[cL].y=y;

    TFO[x][y]=true;

    DFS(x-1,y-1);
    DFS(x-1,y);
    DFS(x-1,y+1);
    DFS(x,y-1);
    DFS(x,y+1);
    DFS(x+1,y-1);
    DFS(x+1,y);
    DFS(x+1,y+1);

    return;
}

void DFS2(Int x,Int y)
{
    if (x<1 || x>h || y<1 || y>w)
    return;
    if (newTFO[x][y])
    return;
    if (newpicture[x][y]==0)
    return;

    newTFO[x][y]=true;

    tL++;
    tail[tL].x=x;
    tail[tL].y=y;
    tail[tL].dist=0;

    DFS2(x-1,y-1);
    DFS2(x-1,y);
    DFS2(x-1,y+1);
    DFS2(x,y-1);
    DFS2(x,y+1);
    DFS2(x+1,y-1);
    DFS2(x+1,y);
    DFS2(x+1,y+1);

    return;
}

void BFS3()
{
    Int uk=1;
    Int cx,cy;
    Int nx,ny;

    while(uk<=tL)
    {
        cx=tail[uk].x;
        cy=tail[uk].y;

        if (tail[uk].dist==6)
        {
            uk++;
            continue;
        }
        else
        {
            for (nx=cx-1;nx<=cx+1;nx++)
            {
                for (ny=cy-1;ny<=cy+1;ny++)
                {
                    if (nx<1 || nx>h || ny<1 || ny>w)
                    continue;

                    if (!newTFO[nx][ny])
                    {
                        tL++;
                        tail[tL].x=nx;
                        tail[tL].y=ny;
                        tail[tL].dist=tail[uk].dist+1;
                        newTFO[nx][ny]=true;
                    }
                }
            }
        }

        uk++;
    }

    return;
}

void DFS4(Int x,Int y)
{
    if (x<1 || x>h || y<1 || y>w)
    return;
    if (newTFO[x][y])
    return;
    if (picture[x][y]==0)
    return;

    newTFO[x][y]=true;

    DFS4(x-1,y-1);
    DFS4(x-1,y);
    DFS4(x-1,y+1);
    DFS4(x,y-1);
    DFS4(x,y+1);
    DFS4(x+1,y-1);
    DFS4(x+1,y);
    DFS4(x+1,y+1);

    return;
}

bool OK(Int x,Int y)
{
    if (x<1 || y<1 || x>h || y>w)
    return false;
    if (newpicture[x][y]==0)
    return false;

    return true;
}

int main()
{
    Int i,j,in,ja;
    Int k;
    Int ctr=0;
    Int sz;

    for (i=0;i<=1601;i++)
    {
        for (j=0;j<=1601;j++)
        {
            TFO[i][j]=false;
            newTFO[i][j]=false;
            toprint[i][j]=false;
        }
    }

    scanf("%d %d",&h,&w);

    for (i=1;i<=h;i++)
    {
        for (j=1;j<=w;j++)
        {
            scanf("%d",&k);

            if (k==0)
            {
                picture[i][j]=false;
            }
            else
            {
                picture[i][j]=true;
            }
            newpicture[i][j]=picture[i][j];
        }
    }

    for (i=1;i<=3;i++)
    {
        for (j=1;j<=h;j++)
        {
            for (in=1;in<=w;in++)
            {
                if (newpicture[j][in]==0)
                {
                    marked[j][in]=false;
                    continue;
                }

                if (!OK(j-1,in) || !OK(j-1,in+1) || !OK(j-1,in-1) || !OK(j+1,in+1) || !OK(j+1,in) || !OK(j+1,in-1) || !OK(j,in-1) || !OK(j,in+1))
                {
                    marked[j][in]=true;
                }
                else
                {
                    marked[j][in]=false;
                }
            }
        }

        for (j=1;j<=h;j++)
        {
            for (in=1;in<=w;in++)
            {
                if (marked[j][in])
                {
                    ctr++;
                    newpicture[j][in]=0;
                }
            }
        }
    }

    for (i=1;i<=h;i++)
    {
        for (j=1;j<=w;j++) ///looking for a potential sun;
        {
            if (picture[i][j]==1 && !TFO[i][j]) ///initial picture sun
            {
                cL=0;
                DFS(i,j);

                for (in=1;in<=cL;in++)
                {
                    if (newpicture[ comp[in].x ][ comp[in].y ]) ///still a part of the sun in the new
                    {
                        tL=0;
                        DFS2(comp[in].x,comp[in].y);
                        break;
                    }
                }

                BFS3();

                /**if (suns.empty())
                {
                    for (in=1;in<=h;in++)
                    {
                        for (ja=1;ja<=w;ja++)
                        {
                            if (newTFO[in][ja])
                            cout<<0;
                            else
                            cout<<picture[in][ja];
                        }
                        cout<<endl;
                    }
                }**/

                ctr=0;
                for (in=1;in<=cL;in++)
                {
                    if (!newTFO[comp[in].x][comp[in].y])
                    {
                        ctr++;
                        DFS4(comp[in].x,comp[in].y);
                    }
                }

                suns.push_back(ctr);
            }
        }
    }

    sz=suns.size();

    sort(suns.begin(),suns.end());

    printf("%d\n",sz);

    for (i=0;i<sz;i++)
    {
        printf("%d",suns[i]);
        if (i!=sz)
        printf(" ");
    }
    printf("\n");

    return 0;
}