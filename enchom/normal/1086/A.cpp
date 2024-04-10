#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int x1,y1;
int x2,y2;
int x3,y3;

int ABS(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

int dist(int a,int b,int c,int d)
{
    return ABS(a-c) + ABS(b-d);
}

vector< pair<int,int> > answer;

void addStuff(int sx,int sy,int ex,int ey)
{
    while(sx != ex || sy != ey)
    {
        answer.push_back(make_pair(sx,sy));

        if (sx < ex)
            sx++;
        else if (sx > ex)
            sx--;
        else if (sy < ey)
            sy++;
        else
            sy--;
    }
}

int main()
{
    int i,j;
    int ans = 1000000;
    int bestans = 1000000;
    int bestx,besty;
    scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);

    for (i=0;i<=1001;i++)
    {
        for (j=0;j<=1001;j++)
        {
            ans = dist(x1,y1,i,j) + dist(x2,y2,i,j) + dist(x3,y3,i,j) + 1;

            if (ans < bestans)
            {
                bestx = i;
                besty = j;
                bestans = ans;
            }
        }
    }

    addStuff(x1,y1,bestx,besty);
    addStuff(x2,y2,bestx,besty);
    addStuff(x3,y3,bestx,besty);

    answer.push_back(make_pair(bestx,besty));

    printf("%d\n",(int)answer.size());

    for (i=0;i<answer.size();i++)
    {
        printf("%d %d\n",answer[i].first,answer[i].second);
    }

    return 0;
}