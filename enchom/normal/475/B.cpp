#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

bool right_horiz[21];
bool down_vertic[21];
int n,m;
bool TFO[21][21];
int ctr=0;

char str[101];

void DFS(int x,int y)
{
    if (x<1 || x>n || y<1 || y>m)
    return;
    if (TFO[x][y])
    return;

    TFO[x][y]=true;
    ctr++;

    if (right_horiz[x])
    DFS(x,y+1);
    else
    DFS(x,y-1);

    if (down_vertic[y])
    DFS(x+1,y);
    else
    DFS(x-1,y);

    return;
}

int main()
{
    int i,j;

    scanf("%d %d",&n,&m);

    scanf("%s",str+1);

    for (i=1;i<=n;i++)
    {
        if (str[i]=='>')
        right_horiz[i]=true;
    }

    scanf("%s",str+1);

    for (i=1;i<=m;i++)
    {
        if (str[i]=='v')
        down_vertic[i]=true;
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            memset(TFO,false,sizeof(TFO));

            ctr=0;

            DFS(i,j);

            if (ctr!=n*m)
            {
                printf("NO\n");
                return 0;
            }
        }
    }

    printf("YES\n");

    return 0;
}