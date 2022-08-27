#include<cmath>
#include<set>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 105
#define inf 1000000020

using namespace std;
typedef long long ll;

int a[maxn],b[maxn],c[maxn],n,m,t;

int main()
{
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    for (int i=1;i<=n;i++){
        scanf("%d",&t);
        a[t]++;
    }
    m=0;
    for (int i=1;i<maxn;i++) if (a[i]) b[++m]=a[i],c[m]=i;
    if (m==2&&b[1]==b[2]) printf("YES\n%d %d\n",c[1],c[2]);
    else printf("NO\n");
    return 0;
}