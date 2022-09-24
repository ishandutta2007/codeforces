// luogu-judger-enable-o2
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;
const double eps=1e-8;
int sgn(double a){return a<-eps?-1:a<eps?0:1;}
int a[500001],b[500001];
ll ans[500001];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            ans[j]+=abs(a[i]-b[j]);
            if(j>1) ans[j]=min(ans[j],ans[j-1]);
        }
    printf("%lld\n",ans[n]);
}