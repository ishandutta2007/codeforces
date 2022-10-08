#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
typedef long long Int;

vector<Int> Graph[100001];
vector<char> EdgeWords[100001];
char input[300001];
Int father[100001];
char mainword[300001];
Int L;
Int counter=0;

///Failure function and KMP stuff
Int F[300001];
Int glookfor;

void RememberState(Int state)
{
    glookfor=state;
    return;
}

void SendToKMP(char ch)
{
    if (mainword[glookfor]==ch)
    {
        glookfor++;
        if (glookfor==L+1)
        {
            counter++;
            glookfor=F[glookfor-1]+1;
        }
    }
    else
    {
        while(mainword[glookfor]!=ch && glookfor>1)
        {
            glookfor=F[glookfor-1]+1;
        }

        if (glookfor==1)
        {
            if (mainword[1]==ch)
            {
                glookfor=2;
            }
        }
        else
        {
            glookfor++;
        }
    }
}

void DFS(Int ver,Int state)
{
    Int i,j;
    Int kid;

    for (i=0;i<Graph[ver].size();i++)
    {
        kid=Graph[ver][i];

        RememberState(state);
        for (j=0;j<EdgeWords[kid].size();j++)
        {
            SendToKMP(EdgeWords[kid][j]);
        }
        DFS(kid,glookfor);
    }

    return;
}

int main()
{
    Int n;
    Int i,j;
    Int lookfor;

    scanf("%I64d",&n);

    for (i=1;i<=n-1;i++)
    {
        scanf("%I64d",&father[i+1]);

        Graph[ father[i+1] ].push_back(i+1);

        scanf("%s",input+1);
        L=strlen(input+1);

        for (j=1;j<=L;j++)
        {
            EdgeWords[i+1].push_back(input[j]);
        }
    }

    scanf("%s",mainword+1);
    L=strlen(mainword+1);

    F[1]=0;
    lookfor=1;

    for (i=2;i<=L;i++)
    {
        if (mainword[i]==mainword[lookfor])
        {
            F[i]=F[i-1]+1;
            lookfor++;
        }
        else
        {
            while(mainword[i]!=mainword[lookfor] && lookfor>1)
            {
                lookfor=F[lookfor-1]+1;
            }

            if (lookfor==1)
            {
                if (mainword[i]==mainword[1])
                {
                    lookfor=2;
                    F[i]=1;
                }
                else
                {
                    F[i]=0;
                }
            }
            else
            {
                F[i]=lookfor;
                lookfor++;
            }
        }
    }

    DFS(1,1);

    printf("%I64d\n",counter);

    return 0;
}