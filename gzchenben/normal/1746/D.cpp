#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,k,t,p[200005];
long long a[200005],val[200005],newp[200005];
vector<int> vec[200005];

void dfs(int x,int c)
{
    if(vec[x].size() == 0)
    {
        val[x] = c * a[x];
        newp[x] = a[x];
        return;
    }
    int nxtc = c / vec[x].size(),res = c % vec[x].size();
    vector<int> tmp;
    val[x] = c * a[x];
    for(auto &p : vec[x])
    {
        dfs(p,nxtc);
        tmp.push_back(newp[p]);
        val[x] += val[p];
    }
    sort(tmp.begin(),tmp.end());
    reverse(tmp.begin(),tmp.end());
    for(int i=0;i<=res-1;i++)
    {
        val[x] += tmp[i];
    }
    newp[x] = a[x] + tmp[res];
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            vec[i].clear(),val[i] = newp[i] = 0;
        for(int i=2;i<=n;i++)
        {
            scanf("%d",&p[i]);
            vec[p[i]].push_back(i);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
        }
        dfs(1,k);
        printf("%lld\n",val[1]);
    }
}