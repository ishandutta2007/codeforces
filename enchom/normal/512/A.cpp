#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

int n;
char words[111][111];
int L[111];
vector<int> Graph[111];
int inside[111];

void AddEdge(int a,int b)
{
    Graph[a].push_back(b);
    inside[b]++;

    return;
}

int q[111];
int qL=0;
bool done;

int MIN(int a,int b)
{
    if (a<b)
    return a;
    else
    return b;
}

void TopSort()
{
    int i;
    int uk=1;
    int v;

    for (i=0;i<=25;i++)
    {
        if (inside[i]==0)
        {
            qL++;
            q[qL]=i;
        }
    }

    while(uk<=qL)
    {
        v=q[uk];

        for (i=0;i<Graph[v].size();i++)
        {
            inside[ Graph[v][i] ]--;

            if (inside[ Graph[v][i] ]==0)
            {
                qL++;
                q[qL]=Graph[v][i];
            }
        }

        uk++;
    }

    if (uk==27)
    done=true;
    else
    done=false;
}

int main()
{
    int i,j;
    int dif;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%s",words[i]+1);
        L[i]=strlen(words[i]+1);
    }

    for (i=1;i<n;i++)
    {
        dif=-1;
        for (j=1;j<=MIN(L[i],L[i+1]);j++)
        {
            if (words[i][j]!=words[i+1][j])
            {
                dif=j;
                break;
            }
        }

        if (dif==-1)
        {
            if (L[i]>L[i+1])
            {
                printf("Impossible\n");
                return 0;
            }
        }
        else
        {
            AddEdge(words[i][dif]-'a',words[i+1][dif]-'a');
        }
    }

    TopSort();

    if (!done)
    {
        printf("Impossible\n");
    }
    else
    {
        for (i=1;i<=26;i++)
        {
            printf("%c",(char)(q[i]+'a'));
        }
        printf("\n");
    }

    return 0;
}