#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<ctime>
#include<utility>
#include<vector>
using namespace std;
#define y0 qgoiqoeinfoiqwef
#define y1 vmpoqmeppjofaqoi
#define yn qoigmnioqonfopiq
#define ff first
#define ss second
struct request
{
    int c,p,num;
}req[1111];
int n=0,k=0,sum=0,cnt=0,ansi;
bool vis[1111];
pair<int,int>pp[1111],ans[1111];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d %d",&req[i].c,&req[i].p),req[i].num=i;
    scanf("%d",&k);
    for(int i=1;i<=k;i++)scanf("%d",&pp[i].ff),pp[i].ss=i;
    sort(pp+1,pp+k+1);
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            if(req[j].c>req[j+1].c)swap(req[j].c,req[j+1].c),swap(req[j].p,req[j+1].p),swap(req[j].num,req[j+1].num);
        }
    }
    for(int i=1;i<=k;i++)
    {
        int mx=-1,mxi=-1;
        for(int j=1;req[j].c<=pp[i].ff&&j<=n;j++)if(!vis[j]&&req[j].p>mx){mx=req[j].p;mxi=j;}
        if(mxi!=-1)
        {
            cnt++;ansi++;
            vis[mxi]=1;
            ans[ansi].ff=req[mxi].num;ans[ansi].ss=pp[i].ss;
            sum+=mx;
        }
    }
    cout<<cnt<<" "<<sum<<endl;
    for(int i=1;i<=ansi;i++)if(ans[i].ff!=0)printf("%d %d\n",ans[i].ff,ans[i].ss);
//  system("pause");
    return 0;
}