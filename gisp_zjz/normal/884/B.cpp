#include<bits/stdc++.h>
#define maxn 1000005
#define m 100020

using namespace std;
int n,t,a[m];

int main()
{
    scanf("%d%d",&n,&t);
    t-=(n-1);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);t-=a[i];
    }
    if (t) printf("NO\n"); else printf("YES\n");
    return 0;
}