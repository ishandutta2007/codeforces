#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char str[4096];
int sum[4096];
int main(){
    int a;
    scanf("%d",&a);
    scanf("%s",str);
    int n=strlen(str);
    long long ret=0;
    for(int i=0;i<n;i++){
        sum[i+1]=sum[i]+str[i]-'0';
    //  printf("%d ",sum[i+1]);
    }
    if(a==0){
        int c=0;
        for(int j=0;j<n;j++){
            c+=upper_bound(sum,sum+j+1,sum[j+1])-lower_bound(sum,sum+j+1,sum[j+1]);
        }
        ret+=(long long)(n*(n+1)/2)*(n*(n+1)/2)-(long long)(n*(n+1)/2-c)*(n*(n+1)/2-c);
    }
    for(int i=1;i*i<=a;i++){
        if(a%i==0){
            int c=0;
            for(int j=0;j<n;j++){
                c+=upper_bound(sum,sum+j+1,sum[j+1]-i)-lower_bound(sum,sum+j+1,sum[j+1]-i);
            }
            int d=0;
            for(int j=0;j<n;j++)d+=upper_bound(sum,sum+j+1,sum[j+1]-a/i)-lower_bound(sum,sum+j+1,sum[j+1]-a/i);
            ret+=(long long)c*d;
            if(i*i!=a)ret+=(long long)c*d;
        //  printf("%d: %d %d\n",i,c,d);
        }
    }
    printf("%I64d\n",ret);
}