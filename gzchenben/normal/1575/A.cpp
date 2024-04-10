#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,ord[1000005];
vector<vector<int> > vec;
bool cmp(int x,int y)
{
    for(int i=0;i<vec[x].size();i++)
    {
        if(vec[x][i]<vec[y][i]) return true;
        if(vec[x][i]>vec[y][i]) return false;
    }
    return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    vec.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char tmp;
            scanf(" %c",&tmp);
            int Now=tmp-'A'+1;
            if(j%2==0) Now=27-Now;
            vec[i].push_back(Now);
        }
    }
    for(int i=1;i<=n;i++) ord[i]=i;
    sort(ord+1,ord+n+1,cmp);
    for(int i=1;i<=n;i++) printf("%d ",ord[i]);
}