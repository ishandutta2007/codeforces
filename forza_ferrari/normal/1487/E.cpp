#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
vector<pair<int,int> > v[5];
int n[5];
map<pair<int,int>,int> mp[5];
int main()
{
    scanf("%d%d%d%d",&n[1],&n[2],&n[3],&n[4]);
    for(register int i=1;i<=4;++i)
        for(register int j=1;j<=n[i];++j)
        {
            int x;
            scanf("%d",&x);
            v[i].push_back(make_pair(x,j));
        }
    for(register int i=2;i<=4;++i)
    {
        int m;
        scanf("%d",&m);
        for(register int j=1;j<=m;++j)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            mp[i][make_pair(x,y)]=1;
        }
    }
    for(register int i=2;i<=4;++i)
    {
        sort(v[i-1].begin(),v[i-1].end());
        for(register int j=0;j<n[i];++j)
        {
            int k=0;
            while(k<n[i-1]&&mp[i][make_pair(v[i-1][k].second,v[i][j].second)])
                ++k;
            if(k==n[i-1])
                v[i][j].first=1<<30;
            else
                v[i][j].first+=v[i-1][k].first;
        }
    }
    sort(v[4].begin(),v[4].end());
    printf("%d\n",v[4][0].first>1e9? -1:v[4][0].first);
    return 0;
}