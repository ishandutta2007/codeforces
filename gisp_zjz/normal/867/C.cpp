#include<cmath>
#include<set>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 200020
#define inf 1000000020

using namespace std;
typedef long long ll;

struct point{
    ll sz,x;
};

bool cmp(point s,point t)
{
    return s.x>t.x;
}

ll ans,n,m,u,v,k,sum,w,tmp,tt,ans1,ans2,j,j2;
point a[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    ans=0;sum=0;
    for (int i=0;i<n;i++)
    {
        scanf("%d%d%d",&a[i].sz,&u,&v);
        sum+=a[i].sz;
        ans+=a[i].sz*v;
        a[i].x=u-v;
    }
    sort(a,a+n,cmp);
    j=0;w=0;
    while (a[j].x>0&&j<n) w+=a[j].sz,ans+=a[j].sz*a[j].x,j++;
    if (w%m<(sum-1)%m+1){
        ans1=ans2=ans;
        tmp=w%m;j2=j;
        j=j2-1;
        while (tmp){
            tt=min(a[j].sz,tmp);
            tmp-=tt;
            ans1-=tt*a[j--].x;
        }
        tmp=(sum-1)%m+1-w%m;
        j=j2;
        while (tmp&&j<n){
            tt=min(a[j].sz,tmp);
            tmp-=tt;
            ans2+=tt*a[j++].x;
        }
        ans=max(ans1,ans2);
    }
    printf("%I64d\n",ans);
    return 0;
}