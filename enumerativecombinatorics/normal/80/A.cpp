#include<stdio.h>
bool isprime(int a){
    bool ret=true;
    for(int i=2;i*i<=a;i++)if(a%i==0)ret=false;
    return ret;
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=a+1;i<b;i++){
        if(isprime(i)){
            printf("NO\n");
            return 0;
        }
    }
    if(!isprime(b))printf("NO\n");
    else printf("YES\n");
}