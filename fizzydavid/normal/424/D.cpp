#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<ctime>
#include<utility>
#include<vector>
using namespace std;
int n,m,a[333][333],dp[4][333][333],tp,tu,td,t,mn=2000000000,mx1,mx2,my1,my2;
inline int cal(int x,int y)
{
    if(x==y)return tp;else return x<y?tu:td;
}
const int LEFT=0,RIGHT=1,UP=2,DOWN=3;
int main()
{
    
    scanf("%d%d%d%d%d%d",&n,&m,&t,&tp,&tu,&td);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dp[LEFT][i][j]=(j==0?0:dp[LEFT][i][j-1]+cal(a[i][j],a[i][j-1]));
            dp[UP][i][j]=(i==0?0:dp[UP][i-1][j]+cal(a[i][j],a[i-1][j]));
            int ti=n-i-1,tj=m-j-1;
            dp[RIGHT][ti][tj]=(tj==m-1?0:dp[RIGHT][ti][tj+1]+cal(a[ti][tj],a[ti][tj+1]));
            dp[DOWN][ti][tj]=(ti==n-1?0:dp[DOWN][ti+1][tj]+cal(a[ti][tj],a[ti+1][tj]));
        }
    }
    for(int x1=0;x1<n;x1++)
    {
        for(int y1=0;y1<m;y1++)
        {
            for(int x2=x1+2;x2<n;x2++)
            {
                for(int y2=y1+2;y2<m;y2++)
                {
                    int d=abs(dp[LEFT][x2][y2]-dp[LEFT][x2][y1]+
                          dp[UP][x2][y1]-dp[UP][x1][y1]+
                          dp[RIGHT][x1][y1]-dp[RIGHT][x1][y2]+
                          dp[DOWN][x1][y2]-dp[DOWN][x2][y2]-t);
                    if(d<mn)mn=d,mx1=x1,mx2=x2,my1=y1,my2=y2;
                }
            }
        }
    }
    printf("%d %d %d %d",mx1+1,my1+1,mx2+1,my2+1);
//  system("pause");
    return 0;
}