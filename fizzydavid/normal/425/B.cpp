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
#define ff first
#define ss second
int n,m,k,a[111][111],res=1<<29;;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    if(n<m)
    {
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[j][i]);
        swap(n,m);
    }
    else
    {
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
    }
    if(k<n)
    {
        for(int t=1;t<=k+1;t++)
        {
            int sum=0;
            for(int i=1;i<=n;i++)
            {
                int cnt=0;
                for(int j=1;j<=m;j++)cnt+=a[i][j]^a[t][j];
                sum+=min(cnt,m-cnt);
            }
            res=min(sum,res);
        }
        cout<<(res<=k?res:-1);
    }
    else
    {
        for(int t=1;t<(1<<m);t++)
        {
            int sum=0;
            for(int i=1;i<=n;i++)
            {
                int cnt=0;
                for(int j=1;j<=m;j++)cnt+=a[i][j]^((t>>(j-1))&1);
                sum+=min(cnt,m-cnt);
            }
            res=min(sum,res);
        }
        cout<<(res<=k?res:-1);
    }
//  system("pause");
    return 0;
}