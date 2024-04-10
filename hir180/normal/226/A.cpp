#include <cstdio>
#include <algorithm>
long long int a,b,x[10001]={1},sum=1;
int main(){
scanf("%lld %lld",&a,&b);
for(int i=1;i<=10000;i++){
x[i]=x[i-1]*3;
x[i]%=b;
}
for(int i=1;i<=a/10000;i++){
sum*=x[10000];
sum%=b;
}
sum*=x[a%10000];
sum%=b;
if(sum==0){
sum=b-1;
}else{
sum--;
}
printf("%lld\n",sum);
return 0;
}