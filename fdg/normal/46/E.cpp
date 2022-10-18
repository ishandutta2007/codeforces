#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <ctime>

using namespace std;

long long D[1501][1501]={0};

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%I64d",&D[i][j]);
    for(int i=0;i<n;i++)
    {
        if (i==0)
        {
            for(int j=1;j<m;j++)
                D[i][j]+=D[i][j-1];
            for(int j=m-2;j>=0;j--)
                D[i][j]=max(D[i][j],D[i][j+1]);
            continue;
        }
        if (i&1)
        {
            for(int j=1;j<=m-1;j++)
                D[i][j]+=D[i][j-1];
            for(int j=0;j<m-1;j++)
                D[i][j]+=D[i-1][j+1];
            D[i][m-1]=-2000000000000000LL;
            for(int j=1;j<m-1;j++)
                D[i][j]=max(D[i][j],D[i][j-1]);
        }
        else
        {
            for(int j=1;j<m;j++)
                D[i][j]+=D[i][j-1];
            for(int j=1;j<m;j++)
                D[i][j]+=D[i-1][j-1];
            D[i][0]=-2000000000000000LL;
            for(int j=m-2;j>=0;j--)
                D[i][j]=max(D[i][j],D[i][j+1]);
        }
    }
/*  for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout << D[i][j] << "    ";
        cout << endl;
    }
*/  long long ans=D[n-1][0];
    for(int i=0;i<m;i++)
        if (D[n-1][i]>ans) ans=D[n-1][i];
    cout << ans << endl;
    return 0;
}