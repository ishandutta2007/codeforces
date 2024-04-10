#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define N 200010
#define inf 100000000
using namespace std;
vector<int>pos[N];
int a[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int r=0;
    for(int i=n;i>=1;i--) pos[a[i]].push_back(i);
    int ax=0,ay=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        int px=pos[ax].empty()?inf:pos[ax].back(),py=pos[ay].empty()?inf:pos[ay].back();
        if(ax==a[i]) px=inf+1;if(ay==a[i]) py=inf+1;
        if(px<=py) ans+=ax!=a[i],ax=a[i];
        else ans+=ay!=a[i],ay=a[i];
        pos[a[i]].pop_back();
    }
    printf("%d\n",ans);
    return 0;
}