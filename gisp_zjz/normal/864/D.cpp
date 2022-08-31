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

int ans,n,m,k,a[maxn],cnt[maxn],nd[maxn];

int main()
{
    scanf("%d",&n);
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++)
    {
        int u;scanf("%d",&u);cnt[u]++;a[i]=u;
        nd[i]=1;
    }
    m=1;k=1;ans=0;
    while (m<=n){
        while (cnt[m]>=nd[m]&&m<=n) m++;
        while (cnt[a[k]]<=nd[a[k]]&&k<=n) nd[a[k]]--,cnt[a[k]]--,k++;
        if (m<=n){
            if (a[k]>m||!nd[a[k]]){
                ans++; cnt[a[k]]--;
                a[k]=m; cnt[m]++;
            }
            nd[a[k]]--;cnt[a[k]]--;k++;
        }
    }
    printf("%d\n",ans);
    for (int i=1;i<n;i++) printf("%d ",a[i]); printf("%d\n",a[n]);
    return 0;
}