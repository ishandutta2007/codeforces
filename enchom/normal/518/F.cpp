#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int n,m;
char grid[2011][2011];

int Down[2011][2011];
int Up[2011][2011];
int Left[2011][2011];
int Right[2011][2011];

int DownSum[2011][2011];
int UpSum[2011][2011];
int RightSum[2011][2011];
int LeftSum[2011][2011];

int DownReach[2011][2011];
int UpReach[2011][2011];
int LeftReach[2011][2011];
int RightReach[2011][2011];

int GetUp(int x1,int y1,int x2,int y2)
{
    if (x1>x2 || y1>y2)
    return 0;

    return Up[x2][y2]-Up[x1-1][y2]-Up[x2][y1-1]+Up[x1-1][y1-1];
}

int GetDown(int x1,int y1,int x2,int y2)
{
    if (x1>x2 || y1>y2)
    return 0;

    return Down[x2][y2]-Down[x1-1][y2]-Down[x2][y1-1]+Down[x1-1][y1-1];
}

int GetRight(int x1,int y1,int x2,int y2)
{
    if (x1>x2 || y1>y2)
    return 0;

    return Right[x2][y2]-Right[x1-1][y2]-Right[x2][y1-1]+Right[x1-1][y1-1];
}

int GetLeft(int x1,int y1,int x2,int y2)
{
    if (x1>x2 || y1>y2)
    return 0;

    return Left[x2][y2]-Left[x1-1][y2]-Left[x2][y1-1]+Left[x1-1][y1-1];
}

int MIN(int a,int b)
{
    if (a<b)
    return a;
    else
    return b;
}

int MAX(int a,int b)
{
    if (a>b)
    return a;
    else
    return b;
}

int main()
{
    //freopen("sample.txt","r",stdin);

    int i,j;
    Int Ans=0;

    scanf("%d %d",&n,&m);

    for (i=1;i<=n;i++)
    {
        scanf("%s",grid[i]+1);
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (grid[i][j]=='#')
            {
                UpSum[i][j]=0;
                LeftSum[i][j]=0;

                UpReach[i][j]=i;
                LeftReach[i][j]=j;
            }
            else
            {
                if (i==1)
                {
                    UpSum[i][j]=1;
                    UpReach[i][j]=1;
                }
                else
                {
                    UpSum[i][j]=UpSum[i-1][j];
                    UpReach[i][j]=UpReach[i-1][j];
                }

                if (j==1)
                {
                    LeftSum[i][j]=1;
                    LeftReach[i][j]=1;
                }
                else
                {
                    LeftSum[i][j]=LeftSum[i][j-1];
                    LeftReach[i][j]=LeftReach[i][j-1];
                }
            }
        }
    }

    for (i=n;i>=1;i--)
    {
        for (j=m;j>=1;j--)
        {
            if (grid[i][j]=='#')
            {
                DownSum[i][j]=0;
                RightSum[i][j]=0;

                DownReach[i][j]=i;
                RightReach[i][j]=j;
            }
            else
            {
                if (i==n)
                {
                    DownSum[i][j]=1;
                    DownReach[i][j]=n;
                }
                else
                {
                    DownSum[i][j]=DownSum[i+1][j];
                    DownReach[i][j]=DownReach[i+1][j];
                }

                if (j==m)
                {
                    RightSum[i][j]=1;
                    RightReach[i][j]=m;
                }
                else
                {
                    RightSum[i][j]=RightSum[i][j+1];
                    RightReach[i][j]=RightReach[i][j+1];
                }
            }
        }
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            Down[i][j]=Down[i-1][j]+Down[i][j-1]-Down[i-1][j-1]+DownSum[i][j];

            Up[i][j]=Up[i-1][j]+Up[i][j-1]-Up[i-1][j-1]+UpSum[i][j];

            Right[i][j]=Right[i-1][j]+Right[i][j-1]-Right[i-1][j-1]+RightSum[i][j];

            Left[i][j]=Left[i-1][j]+Left[i][j-1]-Left[i-1][j-1]+LeftSum[i][j];
        }
    }

    ///Solution

    for (i=2;i<=m-1;i++) ///row
    {
        //cout<<"Processing "<<i<<endl;

        ///Top-to-bottom
        Ans+=(Int)DownSum[1][i]; //no turns

        for (j=2;j<=n-1;j++) //turn at j
        {
            if (UpSum[j][i]==0)
            break;

            ///No more turns
            Ans+=(Int)RightSum[j][i+1];
            Ans+=(Int)LeftSum[j][i-1];

            ///Left turn
            Ans+=(Int)GetUp(j,i+2,j,MIN(RightReach[j][i],m-1));
            Ans+=(Int)GetDown(j,i+1,j,MIN(RightReach[j][i],m-1));

            ///Right turn
            Ans+=(Int)GetUp(j,MAX(LeftReach[j][i],2),j,i-2);
            Ans+=(Int)GetDown(j,MAX(LeftReach[j][i],2),j,i-1);
        }

        ///Bottom-to-top
        Ans+=(Int)UpSum[n][i];

        for (j=n-1;j>=2;j--)
        {
            if (DownSum[j][i]==0)
            break;

            ///No more turns
            Ans+=(Int)RightSum[j][i+1];
            Ans+=(Int)LeftSum[j][i-1];

            ///Left turn
            Ans+=(Int)GetUp(j,MAX(LeftReach[j][i],2),j,i-1);
            Ans+=(Int)GetDown(j,MAX(LeftReach[j][i],2),j,i-2);

            ///Right turns
            Ans+=(Int)GetUp(j,i+1,j,MIN(RightReach[j][i],m-1));
            Ans+=(Int)GetDown(j,i+2,j,MIN(RightReach[j][i],m-1));
        }
    }

    /// /////////////

    for (i=2;i<=n-1;i++) ///column
    {
        ///Left-to-right
        Ans+=(Int)RightSum[i][1];

        for (j=2;j<=m-1;j++)
        {
            if (LeftSum[i][j]==0)
            break;

            ///No more turns
            Ans+=(Int)UpSum[i-1][j];
            Ans+=(Int)DownSum[i+1][j];

            ///Left turns
            Ans+=(Int)GetRight(MAX(2,UpReach[i][j]),j,i-1,j);
            Ans+=(Int)GetLeft(MAX(2,UpReach[i][j]),j,i-2,j);

            ///Right turns
            Ans+=(Int)GetRight(i+1,j,MIN(DownReach[i][j],n-1),j);
            Ans+=(Int)GetLeft(i+2,j,MIN(DownReach[i][j],n-1),j);
        }

        ///Right-to-left
        Ans+=(Int)LeftSum[i][m];

        for (j=m-1;j>=2;j--)
        {
            if (RightSum[i][j]==0)
            break;

            ///No more turns
            Ans+=(Int)UpSum[i-1][j];
            Ans+=(Int)DownSum[i+1][j];

            ///Left turns
            Ans+=(Int)GetRight(i+2,j,MIN(DownReach[i][j],n-1),j);
            Ans+=(Int)GetLeft(i+1,j,MIN(DownReach[i][j],n-1),j);

            ///Right turns
            Ans+=(Int)GetRight(MAX(2,UpReach[i][j]),j,i-2,j);
            Ans+=(Int)GetLeft(MAX(2,UpReach[i][j]),j,i-1,j);
        }
    }

    printf("%lld\n",Ans/2LL);

    return 0;
}