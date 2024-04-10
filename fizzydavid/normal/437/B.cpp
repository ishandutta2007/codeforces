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
#define pb push_back 
#define mp make_pair
#define quit1 return 0
#define quit2 puts("-1");return 0
int vis[20],sum,limit,mx=1,mxb=1;
vector<int>ans;
int main()
{
    cin>>sum>>limit;
    while(mx<=limit)mx*=2,mxb++;mx/=2;mxb--;
    for(int i=1;i<=limit;i++)
    {
        bool ok=0;
        while(!ok)
        {
            int tmp=((vis[mxb]<<mxb)+mx);
            if(limit>=tmp&&sum>=mx)
            {
                sum-=mx;
                ans.pb(tmp);
                vis[mxb]++;
                ok=1;
            }
            else
            {
                ok=0;mx/=2,mxb--;
            }
            if(mxb==0){quit2;}
        }
        if(sum==0)break;
    }
    if(sum!=0){quit2;}
    else
    {
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);
    }
    quit1;
}