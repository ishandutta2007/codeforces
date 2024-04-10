#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int i,n,m,x11,y11,ap[30009];
vector < int > v[30009];
void dfs(int nod)
{
    if(ap[nod]) return ;
    ap[nod]=1;
    for(vector < int > :: iterator it=v[nod].begin();it!=v[nod].end();it++)
        dfs(*it);
    printf("%d ",nod);
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&m);
for(i=1;i<=m;i++)
{
    scanf("%d",&x11);
    scanf("%d",&y11);
    v[x11].push_back(y11);
}
for(i=1;i<=n;i++)
    dfs(i);
printf("\n");
return 0;
}