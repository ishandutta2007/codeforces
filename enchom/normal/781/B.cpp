#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
#include <set>
using namespace std;

int n;
char w1[1111],w2[1111];
int op[4][1111];
int curop[1111];

map<int,int> mymap;
map<int,int>::iterator myit;
int ctr=0;

set<int> myset;

int Add(int x)
{
    myit=mymap.find(x);

    if (myit==mymap.end())
    {
        ctr++;
        mymap.insert(make_pair(x,ctr));

        return ctr;
    }
    else
    {
        return (*myit).second;
    }
}

int C(char ch)
{
    return ch-'A';
}

int incer[2111][4];
char Names[4][1111][4];

int main()
{
    int i,j;
    bool hasprob=true;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%s",w1+1);
        scanf("%s",w2+1);

        op[1][i]=C(w1[1])*26*26+C(w1[2])*26+C(w1[3]);
        op[2][i]=C(w1[1])*26*26+C(w1[2])*26+C(w2[1]);
        curop[i]=1;

        Names[1][i][0]=w1[1];
        Names[1][i][1]=w1[2];
        Names[1][i][2]=w1[3];
        Names[1][i][3]=0;

        Names[2][i][0]=w1[1];
        Names[2][i][1]=w1[2];
        Names[2][i][2]=w2[1];
        Names[2][i][3]=0;

        op[1][i]=Add(op[1][i]);
        op[2][i]=Add(op[2][i]);
    }

    while(hasprob)
    {
        hasprob=false;

        memset(incer,0,sizeof(incer));

        for (i=1;i<=n;i++)
        {
            incer[ op[ curop[i] ][i] ][ curop[i] ]++;
        }

        for (i=1;i<=ctr;i++)
        {
            if (incer[i][1]+incer[i][2]>1) ///Problematic
            {
                hasprob=true;
                if (incer[i][2]>1) ///Very problematic
                {
                    printf("NO\n");
                    return 0;
                }
            }
        }

        for (i=1;i<=n;i++)
        {
            if (curop[i]==2)
            continue;

            if (incer[ op[ curop[i] ][i] ][1]+incer[ op[ curop[i] ][i] ][2]>1)
            {
                curop[i]=2;
            }
        }
    }

    printf("YES\n");

    for (i=1;i<=n;i++)
    {
        /*if (myset.find( op[ curop[i] ][i] )!=myset.end())
        {
            while(1);
        }

        myset.insert( op[ curop[i] ][i] );*/

        printf("%s\n",Names[ curop[i] ][i]);
    }

    return 0;
}