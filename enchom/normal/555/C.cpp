#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
using namespace std;
#define INF 1999999999

int n,q;
pair<int,int> cords[200111];
char tp[200111][3];

map<int,int> mymap;
map<int,int>::iterator myit;

set< pair<int,int> > dups;

int LEAFOFFSET=1;
int ITU[1000001];
int ITL[1000001];
int realX[1000001];

inline int MIN(int a,int b)
{
    if (a<b)
    return a;
    else
    return b;
}

int FirstRec(int ver,int val)
{
    if (ver>LEAFOFFSET)
    return ver-LEAFOFFSET;

    if (ITL[2*ver]<=val)
    return FirstRec(2*ver,val);
    else
    return FirstRec(2*ver+1,val);
}

int GetFirst(int ver,int val)
{
    return FirstRec(ver,val);
}

int FindFirstU(int ind,int val)
{
    int cur=ind+LEAFOFFSET;
    int goal=-1;

    if (ITL[cur]<=val)
    {
        goal=cur;
    }

    if (goal==-1)
    {
        while(cur>1)
        {
            if (cur%2==0)
            {
                if (ITL[cur+1]<=val)
                {
                    goal=cur+1;
                    break;
                }
            }

            cur/=2;
        }
    }

    if (goal==-1)
    return -1;
    else
    return GetFirst(goal,val);
}

///

int LastRec(int ver,int val)
{
    if (ver>LEAFOFFSET)
    return ver-LEAFOFFSET;

    if (ITU[2*ver+1]<=val)
    return LastRec(2*ver+1,val);
    else
    return LastRec(2*ver,val);
}

int GetLast(int ver,int val)
{
    return LastRec(ver,val);
}

int FindLastL(int ind,int val)
{
    if (ind==0)
    return -1;

    int cur=ind+LEAFOFFSET;
    int goal=-1;

    if (ITU[cur]<=val)
    {
        goal=cur;
    }

    if (goal==-1)
    {
        while(cur>1)
        {
            if (cur%2==1)
            {
                if (ITU[cur-1]<=val)
                {
                    goal=cur-1;
                    break;
                }
            }

            cur/=2;
        }
    }

    if (goal==-1)
    return -1;
    else
    return GetLast(goal,val);
}

void UpdateU(int ind,int val)
{
    ind+=LEAFOFFSET;

    ITU[ind]=val;
    ind/=2;

    while(ind>0)
    {
        ITU[ind]=MIN(ITU[2*ind],ITU[2*ind+1]);
        ind/=2;
    }

    return;
}

void UpdateL(int ind,int val)
{
    ind+=LEAFOFFSET;

    ITL[ind]=val;
    ind/=2;

    while(ind>0)
    {
        ITL[ind]=MIN(ITL[2*ind],ITL[2*ind+1]);
        ind/=2;
    }

    return;
}

int main()
{
    int i;
    int x,y;
    int ctr=0;
    int r;
    int reach;
    int realind;

    scanf("%d %d",&n,&q);

    LEAFOFFSET=1;
    while(LEAFOFFSET<200000)
    LEAFOFFSET*=2;
    LEAFOFFSET--;

    for (i=LEAFOFFSET+1;i<=2*LEAFOFFSET+1;i++)
    {
        ITL[i]=INF;
        ITU[i]=INF;
    }

    for (i=LEAFOFFSET;i>=1;i--)
    {
        ITL[i]=INF;
        ITU[i]=INF;
    }

    for (i=1;i<=q;i++)
    {
        scanf("%d %d",&y,&x);
        scanf("%s",tp[i]);

        cords[i]=make_pair(x,y);

        mymap.insert(make_pair(y,0));
    }

    for (myit=mymap.begin();myit!=mymap.end();myit++)
    {
        ctr++;
        (*myit).second=ctr;

        realX[ctr]=(*myit).first;
    }

    for (i=1;i<=q;i++)
    {
        x=cords[i].first;
        y=cords[i].second;

        if (dups.find(make_pair(x,y))!=dups.end())
        {
            printf("0\n");
            continue;
        }

        dups.insert(make_pair(x,y));

        ///cout<<"going with "<<x<<";"<<y<<endl;

        if (tp[i][0]=='U')
        {
            realind=(*mymap.find(y)).second;

            r=FindFirstU(realind+1,y);

            //cout<<"r is "<<r<<endl;

            if (r==-1)
            {
                reach=1;
            }
            else
            {
                reach=(n-realX[r]+1)+1;
            }

            ///cout<<"reach is "<<reach<<endl;

            printf("%d\n",x-reach+1);


            UpdateU(realind,reach);
        }
        else ///L
        {
            realind=(*mymap.find(y)).second;

            r=FindLastL(realind-1,x);

            if (r==-1)
            {
                reach=1;
            }
            else
            {
                reach=realX[r]+1;
            }

            printf("%d\n",y-reach+1);

            //cout<<"Updating "<<realind<<" with "<<reach<<endl;
            UpdateL(realind,reach);
        }

        //cout<<"--------------------------------"<<endl;
    }

    return 0;
}