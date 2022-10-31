#include<cstdio>
#include<iostream>
const int N=100010;
int p[N],xx[N],yy[N];
int sum,n,num;
int main()
{
    scanf("%d%d",&sum,&n);
    for (int i=1;i<=n;i++) xx[i&-i]++;
    for (int i=17;i>=0;i--)
    while (sum>=(1<<i)&&xx[1<<i]>yy[1<<i]) sum-=1<<i,yy[1<<i]++;
    if (sum) {printf("-1\n");return 0;}
    for (int i=1;i<=n;i++)
    if (yy[i&-i]) yy[i&-i]--,p[++num]=i;
    printf("%d\n",num);
    for (int i=1;i<=num;i++) printf("%d%c",p[i],i<num?' ':'\n');
    return 0;
}