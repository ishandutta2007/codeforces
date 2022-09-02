#include <cstdio>
long long n,m,a,sum=1;
int main(){
  scanf("%lld%lld%lld",&n,&m,&a);
    if(n%a==0){
      sum*=n/a;
    }else{
      sum*=(n/a+1);
    }
    if(m%a==0){
      sum*=m/a;
    }else{
      sum*=(m/a+1);
    }
  printf("%lld\n",sum);
  return 0;
}