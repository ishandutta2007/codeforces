#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1000010
#define ll long long
using namespace std;
ll a[N],b[N];
int px[N],py[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]+=a[i-1];
	for(int i=1;i<=n;i++) scanf("%lld",&b[i]),b[i]+=b[i-1];
	int fl=0;
	if(b[n]>a[n]) swap(a,b),fl=1;
	int u=0,v=0,x=0;
	memset(px,-1,sizeof(px));
	for(;v<=n;v++)
    {
        for(;a[v]>=b[u+1] && u+1<=n;u++);
        x=a[v]-b[u];
        if(px[x]==-1) px[x]=v,py[x]=u;
        else break;
    }
    if(fl) swap(a,b),swap(v,u),swap(px[x],py[x]);
    printf("%d\n",v-px[x]);
    for(int i=px[x]+1;i<=v;i++) printf("%d ",i);
    puts("");
    printf("%d\n",u-py[x]);
    for(int i=py[x]+1;i<=u;i++) printf("%d ",i);
	return 0;
}