#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
vector<int> g[3001],f;
int mx;
int main(){
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
    }
    ans=1e18;
    for (int i=1;i<=m;i++)
        sort(g[i].begin(),g[i].end()),mx=max(mx,(int)g[i].size());
    for (int i=1;i<=mx+1;i++){
        long long sum=0;
        f.clear();
        int sum1=g[1].size();
        for (int j=2;j<=m;j++)
            for (int k=0;k<g[j].size();k++)
                if (g[j].size()-k>=i)sum+=g[j][k],sum1++;
                else
                    f.push_back(g[j][k]);
        sort(f.begin(),f.end());
        if (f.size()+sum1<i)continue;
        for (int j=0;j+sum1+1<=i&&j<f.size();j++)
            sum+=f[j];
        ans=min(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}