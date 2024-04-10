#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

const Int MOD=1000000007LL;

int n;
char ch[5011];

int FDif[5011][5011];

int GetDif(int x,int y)
{
    if (FDif[x][y]!=-1)
    return FDif[x][y];

    if (ch[x]!=ch[y] || x>n || y>n)
    return 0;
    else
    FDif[x][y]=1+GetDif(x+1,y+1);

    return FDif[x][y];
}

int F[5011][5011];
int SuffixSums[5011][5011];

int GetSum(int L,int k)
{
    if (L<1)
    L=1;

    if (L>k)
    return 0;

    return SuffixSums[L][k];
}

int main()
{
    int i,j;
    int L;
    int d1,d2;

    memset(FDif,-1,sizeof(FDif));

    scanf("%d",&n);

    scanf("%s",ch+1);

    for (i=1;i<=n;i++)
    {
        for (j=i;j>=1;j--)
        {
            ///Solving F[j][i] - segment from j to i

            if (ch[j]=='0')
            {
                F[j][i]=0;
            }
            else
            {
                if (j==1)
                {
                    //cout<<"..."<<endl;
                    F[j][i]=1;
                }
                else
                {
                    L=j-1-(i-j);

                    //cout<<"Adding "<<L+1<<"~"<<j-1<<endl;
                    F[j][i]=GetSum(L+1,j-1);
                    //cout<<F[j][i]<<endl;

                    if (L>=1)
                    {
                        d1=GetDif(L,j)+L;
                        d2=GetDif(L,j)+j;

                        //cout<<"Difference at "<<d1<<" and "<<d2<<endl;

                        if (d1<j)
                        {
                            if (ch[d1]<ch[d2])
                            F[j][i]+=F[L][j-1];
                        }
                    }
                }
            }

            //cout<<"F["<<j<<"]["<<i<<"]="<<F[j][i]<<endl<<endl;

            if (F[j][i]>=MOD)
            F[j][i]-=MOD;

            if (i!=j)
            SuffixSums[j][i]=SuffixSums[j+1][i]+F[j][i];
            else
            SuffixSums[j][i]=F[j][i];

            if (SuffixSums[j][i]>=MOD)
            SuffixSums[j][i]-=MOD;
        }
    }

    printf("%d\n",GetSum(1,n));

    return 0;
}