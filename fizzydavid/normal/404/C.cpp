#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
int n,k,s,zc;
vector<int> g[100100],c[100100];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);g[x].push_back(i);if(x==0)zc++;
    }
    if(zc!=1){cout<<-1;return 0;}
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<g[i].size();j++)
        {
            bool ok=false;int t;
            for(t=0;t<g[i-1].size();t++){if(c[g[i-1][t]].size()<k){ok=1;break;}}
            if(!ok)
            {
                cout<<-1;return 0;
            }
            else
            {
                s++;
                c[g[i][j]].push_back(g[i-1][t]);
                c[g[i-1][t]].push_back(g[i][j]);
            }
        }
    }
    cout<<s<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<c[i].size();j++)
        {
            if(i<c[i][j])printf("%d %d\n",i,c[i][j]);
        }
    }
    return 0;
}