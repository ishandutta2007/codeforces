#include<bits/stdc++.h>
#define maxn 1000500

using namespace std;
typedef long long ll;
ll a[maxn],n,k,x,y,l,r,mid,t;
bool flag;

int main()
{
    for (int i=1;i<=1000001;i++) a[i]=1ll*i*i*i;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%lld%lld",&x,&y);
        t=x*y; flag=true;
        l=0; r=1000001;
        while (r-l>1){
            mid=(l+r)/2;
            if (a[mid]>t) r=mid; else l=mid;
        }
        if (a[l]!=t) flag=false;
        else {
            if (x%l) flag=false;
            if (y%l) flag=false;
        }
        if (flag) puts("Yes"); else puts("No");
    }
    return 0;
}