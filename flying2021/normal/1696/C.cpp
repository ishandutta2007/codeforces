#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define N 1000010
using namespace std;
typedef long long ll;
pair<int,ll>a[N],b[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n0,m0,k;scanf("%d%d",&n0,&k);
        int n=0,m=0;
        for(int i=1,x;i<=n0;i++)
        {
            scanf("%d",&x);ll c=1;
            while(x%k==0) c*=k,x/=k;
            if(n && a[n].first==x) a[n].second+=c;
            else a[++n]={x,c};
        }
        scanf("%d",&m0);
        for(int i=1,x;i<=m0;i++)
        {
            scanf("%d",&x);ll c=1;
            while(x%k==0) c*=k,x/=k;
            if(m && b[m].first==x) b[m].second+=c;
            else b[++m]={x,c};
        }
        if(n!=m) puts("No");
        else
        {
            bool can=true;
            for(int i=1;i<=n;i++) if(a[i]!=b[i]){can=false;break;}
            if(can) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}