#include<stdio.h>
main(){
    int t;
    scanf("%d",&t);
    long long int a[32];
    a[0]=1;
    for(int i=1;i<32;i++)
    {
        a[i]=a[i-1]*2;
        if(a[i]>1e9)
            break;
    }
    while(t--){
        long long int n;
        scanf("%I64d",&n);
        long long int sum=(n+1)*n/2;
        for(int i=0;a[i]<=n;i++)
            sum-=a[i]*2;
        printf("%I64d\n",sum);
    }
}