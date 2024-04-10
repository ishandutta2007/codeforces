#include<map>
#include<stdio.h>
using namespace std;
main(){
    map <long long int,long long int> m;
    map <long long int,long long int> m2;
    int n,k;
    long long int sum=0;
    scanf("%d %d",&n,&k);
    int a[300000];
    if(k!=1){
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
    {
        m[a[i]]++;
        if(a[i]!=0){
        if(a[i]%k==0)
            m2[a[i]]+=m[a[i]/k];
        if(a[i]%(k*k)==0)
            sum+=m2[a[i]/k];
        }
        else
        {
         sum+=(m[a[i]]-1)*(m[a[i]]-2)/2;
        }
    }
    }
    else{
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
        {
          m[a[i]]++;
          sum+=(m[a[i]]-1)*(m[a[i]]-2)/2;
        }

    }
    printf("%I64d",sum);
    return 0;
}