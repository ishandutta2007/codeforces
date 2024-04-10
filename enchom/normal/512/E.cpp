#include <iostream>
#include <stdio.h>
using namespace std;

bool Start[1001][1001];
bool Target[1001][1001];

pair<int,int> Moves1[1001];
int L1=0;
pair<int,int> Moves2[1001];
int L2=0;

int n;

void TargetMove(int k)
{
    int i;
    int maxunder=-1,minover=9999;
    int changed;

    for (i=2;i<=n;i++)
    {
        if (Target[1][i] && i<k && i>maxunder)
        maxunder=i;

        if (Target[1][i] && i>k && i<minover)
        minover=i;
    }

    for (i=maxunder+1;i<=minover-1;i++)
    {
        if (Target[maxunder][i] && Target[i][minover])
        {
            changed=i;
            break;
        }
    }

    L2++;
    Moves2[L2]=make_pair(1,changed);

    Target[1][changed]=true;
    Target[changed][1]=true;

    Target[minover][maxunder]=false;
    Target[maxunder][minover]=false;

    return;
}

void GetTargetMoves()
{
    int i;

    for (i=2;i<=n;i++)
    {
        while(!Target[1][i])
        {
            TargetMove(i);
        }
    }

    return;
}

void StartMove(int k)
{
    int i;
    int maxunder=-1,minover=9999;
    int changed;

    for (i=2;i<=n;i++)
    {
        if (Start[1][i] && i<k && i>maxunder)
        maxunder=i;

        if (Start[1][i] && i>k && i<minover)
        minover=i;
    }

    for (i=maxunder+1;i<=minover-1;i++)
    {
        if (Start[maxunder][i] && Start[i][minover])
        {
            changed=i;
            break;
        }
    }

    L1++;
    Moves1[L1]=make_pair(maxunder,minover);

    Start[1][changed]=true;
    Start[changed][1]=true;

    Start[minover][maxunder]=false;
    Start[maxunder][minover]=false;

    return;
}

void GetStartMoves()
{
    int i;

    for (i=2;i<=n;i++)
    {
        while (!Start[1][i])
        {
            StartMove(i);
        }
    }

    return;
}

int main()
{
    int i;
    int a,b;

    scanf("%d",&n);

    for (i=1;i<n;i++)
    {
        Start[i][i+1]=true;
        Start[i+1][i]=true;
        Target[i][i+1]=true;
        Target[i+1][i]=true;
    }

    Start[1][n]=true;
    Start[n][1]=true;
    Target[1][n]=true;
    Target[n][1]=true;

    for (i=1;i<=n-3;i++)
    {
        scanf("%d %d",&a,&b);
        Start[a][b]=true;
        Start[b][a]=true;
    }

    for (i=1;i<=n-3;i++)
    {
        scanf("%d %d",&a,&b);
        Target[a][b]=true;
        Target[b][a]=true;
    }

    GetStartMoves();
    GetTargetMoves();

    printf("%d\n",L1+L2);

    for (i=1;i<=L1;i++)
    {
        printf("%d %d\n",Moves1[i].first,Moves1[i].second);
    }

    for (i=L2;i>=1;i--)
    {
        printf("%d %d\n",Moves2[i].first,Moves2[i].second);
    }

    return 0;
}