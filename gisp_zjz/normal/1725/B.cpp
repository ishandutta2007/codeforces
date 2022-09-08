#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int l=1,r=n,ans=0;
    while(r>=l)
    {
        int need=k/a[r]+1;
        if(l+need-1>r) break;
        r--; l+=need-1;
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}