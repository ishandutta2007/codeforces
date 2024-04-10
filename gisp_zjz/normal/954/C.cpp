#include<bits/stdc++.h>
#define maxn 202030

using namespace std;
int n,x,y,a[maxn];
int main()
{
    scanf("%d",&n);for (int i=0;i<n;i++) scanf("%d",&a[i]);
    y=-1;
    for (int i=1;i<n;i++)
    if (abs(a[i]-a[i-1])!=1){
        if (a[i]==a[i-1]) {puts("NO");return 0;}
        if (y!=-1&&abs(a[i]-a[i-1])!=y) {puts("NO");return 0;} else y=abs(a[i]-a[i-1]);
    }
    if (y!=-1){
        for (int i=1;i<n;i++)
        {
            if (abs(a[i]-a[i-1])==1&&min(a[i],a[i-1])%y==0) {puts("NO");return 0;}
        }
    }
    else y=1;
    printf("YES\n");
    printf("1000000000 %d\n",y);
    return 0;
}