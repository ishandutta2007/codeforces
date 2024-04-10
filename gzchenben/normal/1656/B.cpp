#include<cstdio>
#include<map>
using namespace std;
int n,t,k,a[200005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        map<int,bool> mp;
        for(int i=1;i<=n;i++) mp[a[i]]=true;
        bool flag=false;
        for(int i=1;i<=n;i++) if(mp[a[i]+k]) flag=true;
        printf(flag ? "YES\n" : "NO\n");
    }
}