#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct event
{
    int id;
    int t;
};

int n,M,T;
event events[50001];
int L=0;

int AssignedTo[50001];
bool Added[50001];

char str[11];

bool SE(event a,event b)
{
    return a.t<b.t;
}

int INT(char ch)
{
    return ch-'0';
}

multimap<int,int> mymap;
multimap<int,int>::iterator myit;

int main()
{
    int i;
    int h,m,s;
    int t;
    int remid;
    int R=0;
    bool reachedM=false;

    scanf("%d %d %d",&n,&M,&T);

    for (i=1;i<=n;i++)
    {
        scanf("%s",str+1);

        h=INT(str[1])*10+INT(str[2]);
        m=INT(str[4])*10+INT(str[5]);
        s=INT(str[7])*10+INT(str[8]);

        t=h*3600+m*60+s;

        L++;
        events[L].t=t;
        events[L].id=i;
    }

    sort(events+1,events+1+L,SE);

    for (i=1;i<=L;i++)
    {
        if (mymap.size()==M)
        reachedM=true;

        ///cout<<"Time "<<events[i].t<<endl;

        while(!mymap.empty())
        {
            myit=mymap.begin();

            if ( (*myit).first<=events[i].t )
            {
                ///cout<<"Releasing "<<(*myit).second<<endl;

                mymap.erase(myit);
            }
            else
            break;
        }

        if (mymap.size()==M)
        {
            myit=mymap.end();
            myit--;

            AssignedTo[ events[i].id ]=AssignedTo[ (*myit).second ];

            remid=(*myit).second;

            mymap.erase(myit);

            mymap.insert(make_pair( events[i].t+T,remid ));

            ///cout<<"Not able to add it, extending "<<remid<<" to "<<events[i].t+T<<endl;
        }
        else
        {
            ///cout<<"Adding "<<events[i].id<<" until "<<events[i].t+T<<endl;
            mymap.insert(make_pair(events[i].t+T,events[i].id));

            R++;
            AssignedTo[ events[i].id ]=R;
        }
    }

    if (mymap.size()==M)
    reachedM=true;

    if (!reachedM)
    {
        printf("No solution\n");
        return 0;
    }

    printf("%d\n",R);

    for (i=1;i<=n;i++)
    {
        printf("%d\n",AssignedTo[i]);
    }

    return 0;
}
/**
5 1 10
00:00:00
00:00:09
00:00:18
00:00:28
00:00:36
**/