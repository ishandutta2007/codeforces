#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
#define ll long long
using namespace std;
ll a[N],p[7];
struct node{
    int x;
    ll v;
    bool operator <(const node a)const{return v<a.v;}
}b[N*12];
int tt;
int s[N];
int main()
{
    int n;
    for(int _=1;_<=6;_++) scanf("%lld",&p[_]);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
        for(int _=1;_<=6;_++) b[++tt]=(node){i,a[i]-p[_]};
    sort(b+1,b+tt+1);
    int r=1,cnt=0;
    ll ans=1e18;
    for(int i=1;i<=tt;i++)
    {
        for(;r<=tt && cnt<n;r++)
        {
            if(!s[b[r].x]) cnt++;
            s[b[r].x]++;
        }
        if(cnt==n) ans=min(ans,b[r-1].v-b[i].v);
        s[b[i].x]--;
        if(!s[b[i].x]) cnt--;
    }
    printf("%lld\n",ans);
    return 0;
}