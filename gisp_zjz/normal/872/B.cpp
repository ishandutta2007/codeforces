#include<bits/stdc++.h>
#define maxn 200020

using namespace std;

int n,k,a[maxn],l,r;

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    l=a[0];r=a[0];
    for (int i=1;i<n;i++){l=min(l,a[i]);r=max(r,a[i]);}
    if (k==1) printf("%d\n",l);
    else if (k==2) printf("%d\n",max(a[0],a[n-1]));
    else printf("%d\n",r);
    return 0;
}