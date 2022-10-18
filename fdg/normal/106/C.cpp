#include <cstdio>
#include <iostream>
#include <vector>
#include <memory.h>
#include <cmath>

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int C,m,c0,d0,a[101],b[101],c[101],d[101];
    cin >> C >> m >> c0 >> d0;
    for(int i=0;i<m;i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    vector <int> w,p;
    int best[1002];
    memset(best,-1,sizeof(best));
    best[0]=0;
    for(int i=0;i<m;i++)
    {
        int k=min(C/c[i],a[i]/b[i]);
        for(int j=0;j<k;j++)
        {
            for(int t=C;t>=0;t--)
                if (t+c[i]<=C&&best[t]!=-1) best[t+c[i]]=max(best[t+c[i]],best[t]+d[i]);
        }
    }
    for(int j=0;j<C;j++)
    {
        for(int t=C;t>=0;t--)
            if (t+c0<=C&&best[t]!=-1) best[t+c0]=max(best[t+c0],best[t]+d0);
    }
    int ans=-1;
    for(int i=0;i<=C;i++)
        ans=max(ans,best[i]);
    cout << ans << endl;
    return 0;
}