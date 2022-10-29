#include<iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
  
const int MOD = 1073741824;  
const int Maxn = 1000005;  
int w[6600];  
int ans[Maxn], n;  
bool isPrime(int n) {  
    if(n<=1)return false;  
    if(n==2)return true;  
    if(n!=2&&n%2==0)return false;  
    int i;  
    for(i=3;i*i<=n;i+=2)  
        if(n%i==0)return false;  
    return true;  
}   
int count(int n){  
    if(ans[n]!=-1)return ans[n];  
    int a=n, i=0, sum=1;  
    while(a!=1 && i<n){  
        int cnt=0;  
        while(a%w[i]==0){  
            ++cnt;  
            a /= w[i];  
        }  
        if(cnt) sum*=(1+cnt);  
        ++i;  
    }  
    ans[n] = sum;  
    return ans[n];  
}  
  
int main(){  
   int a,b,c;  
   n=0;  
   for(int i=1; i<(1<<16); i++)   
       if(isPrime(i)) w[n++]=i;  
  
   memset(ans, -1, sizeof(ans));  
  
   while(~scanf("%d%d%d",&a,&b,&c)){  
       int sum=0;  
       for(int i=1; i<=a; ++i)  
       for(int j=1; j<=b; ++j)  
       for(int k=1; k<=c; ++k){  
        sum += count(i*j*k);  
        if(sum > MOD) sum %= MOD;  
       }  
       printf("%d\n",sum);  
   }  
   return 0;  
}