#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct event
{
    int t;
    bool home;
    int num;
    bool yellow;
};

char hometeam[101];
char guestteam[101];

int n;
event events[1001];

int ctr[301];

bool SE(event a,event b)
{
    return a.t<b.t;
}

int main()
{
    int i;
    int player;
    char ch;

    scanf("%s",hometeam);
    scanf("%s",guestteam);
    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&events[i].t);

        ch='.';
        while(ch!='h' && ch!='a')
        {
            scanf("%c",&ch);
        }

        if (ch=='h')
        events[i].home=true;
        else
        events[i].home=false;

        scanf("%d",&events[i].num);

        ch='.';
        while(ch!='y' && ch!='r')
        {
            scanf("%c",&ch);
        }

        if (ch=='y')
        events[i].yellow=true;
        else
        events[i].yellow=false;
    }

    sort(events+1,events+1+n,SE);

    for (i=1;i<=n;i++)
    {
        player=events[i].num;
        if (!events[i].home)
        player+=100;

        if (ctr[player]>=2)
        continue;

        if (events[i].yellow)
        ctr[player]++;
        else
        ctr[player]+=2;

        if (ctr[player]>=2)
        {
            if (events[i].home)
            printf("%s ",hometeam);
            else
            printf("%s ",guestteam);

            if (events[i].home)
            printf("%d ",player);
            else
            printf("%d ",player-100);

            printf("%d\n",events[i].t);
        }
    }

    return 0;
}