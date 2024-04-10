#include <iostream>
using namespace std;

bool possible[260][60];

int main()
{
    int i,j,in,k;
    int n,m;
    for (i=0;i<=259;i++)
    {
        for (j=0;j<=59;j++)
        possible[i][j]=false;
    }
    possible[0][0]=true;
    for (k=3;k<=6;k++)
    for (in=1;in<=130;in++)
    for (i=250;i>=0;i--)
    {
        for (j=50;j>=0;j--)
        {
            if (possible[i][j])
            {
                possible[i+k][j+1]=true;
            }
        }
    }
    cin>>n>>m;
    for (i=0;i<=n;i++)
    {
        if (possible[m-2*i][n-i])
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}