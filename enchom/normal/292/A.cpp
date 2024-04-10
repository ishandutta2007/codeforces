#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

struct query
{
    Int timesent;
    Int msges;
};

Int n;
query queries[1001];

int main()
{
    Int i;
    Int lasttime,lastmsg;
    Int maxmsginside=0;
    Int curtime;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&queries[i].timesent,&queries[i].msges);
    }

    lasttime=0;
    lastmsg=0;

    for (i=1;i<=n;i++)
    {
        curtime=queries[i].timesent;
        lastmsg=lastmsg-(curtime-lasttime);
        if (lastmsg<0)
        {
            lastmsg=0;
        }
        lasttime=curtime;

        lastmsg=lastmsg+queries[i].msges;

        if (lastmsg>maxmsginside)
        {
            maxmsginside=lastmsg;
        }
    }

    printf("%I64d %I64d\n",lasttime+lastmsg,maxmsginside);

    return 0;
}