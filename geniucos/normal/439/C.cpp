#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int ai,i,j,n,m,N,k,p,a[100009],b[100009];
vector < int > v[100009];
int mod(int x)
{
    if(x<0) return -x;
    return x;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&N);
scanf("%d",&k);
scanf("%d",&p);
for(i=1;i<=N;i++)
{
    scanf("%d",&ai);
    if(ai%2==0) a[++n]=ai;
    else b[++m]=ai;
}
for(i=1;i<=k;i++)
{
    if(i<=p)
    {
        if(n) v[i].push_back(a[n--]);
        else
        {
            if(m<=1)
            {
                printf("NO\n");
                return 0;
            }
            v[i].push_back(b[m]);
            v[i].push_back(b[m-1]);
            m-=2;
        }
    }
    else
    {
        if(m)
        {
            v[i].push_back(b[m--]);
        }
        else
        {
            printf("NO\n");
                return 0;
        }
    }
}
for(i=1;i<=n;i++)
    v[k].push_back(a[i]);
if(m%2==1)
{
    printf("NO\n");
    return 0;
}
while(m)
{
    v[1].push_back(b[m]);
    v[1].push_back(b[m-1]);
    m-=2;
}
printf("YES\n");
for(i=1;i<=k;i++)
{
    printf("%d ",v[i].size());
    for(j=0;j<v[i].size();j++)
        printf("%d ",v[i][j]);
    printf("\n");
}
return 0;
}