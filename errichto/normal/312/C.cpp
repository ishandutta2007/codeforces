#include<cstdio>
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    if(n*(n-1)/2<=k) return !printf("no solution");
    for(int i=0;i<n;++i) printf("%d %d\n",i,3000*i);
    return 0;
}