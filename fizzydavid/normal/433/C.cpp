#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
long long n,m,a[100100],c[100100],sum;
vector<int>con[100100];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)scanf("%d",&a[i]);
    for(int i=1;i<m;i++)sum+=abs(a[i]-a[i+1]);
    for(int i=1;i<=m;i++)
    {
        if(i!=1&&a[i]!=a[i-1])con[a[i]].push_back(a[i-1]);
        if(i!=m&&a[i]!=a[i+1])con[a[i]].push_back(a[i+1]);
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        sort(con[i].begin(),con[i].end());
        int mid=con[i].size()/2;
        for(int j=0;j<con[i].size();j++)
        {
            c[i]+=abs(con[i][j]-i)-abs(con[i][j]-con[i][mid]);
        }
        ans=max(c[i],ans);
    }
    ans=sum-ans;
    cout<<ans;
//  system("pause");
    return 0;
}