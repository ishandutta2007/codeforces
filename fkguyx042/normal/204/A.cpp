#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
long long l,r;
long long work(long long x)
{ int Len=(int)log10(x)+1;
  long long sum=0;
    long long Last;  
    if(x<10)return x;  
    Last=x%10;  
    sum=x/10+9;  
    while(x>=10)x/=10;  
    if(x>Last)sum--;  
    return sum;  
}  
int main()
{ scanf("%I64d%I64d",&l,&r);
  printf("%I64d\n",work(r)-work(l-1));
}