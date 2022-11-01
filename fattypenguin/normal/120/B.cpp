#include<stdio.h>

const int V = 1100;

int n, m;
int a[V];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d%d",&n,&m);
    m--;

    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    while (a[m] == 0) m = (m + 1) % n;

    printf("%d\n",m+1);
}