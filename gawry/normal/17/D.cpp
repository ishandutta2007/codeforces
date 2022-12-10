#include<cstdio>
#include<iostream>
using namespace std;
#define MAX 1100000
long long power(long long x,long long n,long long m){
  long long r=1;
  while(n){
    if(n&1)r=r*x%m;
    n>>=1;
    x=x*x%m;
  }
  return r;
}
char b[MAX],n[MAX];
int c;
main(){
  scanf(" %s %s %d",b,n,&c);
  long long x=1,bb=0;
  for(int i=0;b[i];i++)bb=(10*bb+b[i]-'0')%c;
//  cout<<bb<<" "<<x<<endl;
  int pos=0;
  while(n[pos])pos++;
  pos--;
  while(n[pos]=='0'){n[pos]='9';pos--;}
  n[pos]--;
  for(int i=0;n[i];i++){
//  cout<<n[i]-'0'<<endl;
    x=power(x,10,c)*power(bb,n[i]-'0',c)%c;
  }
//  cout<<x<<endl;
  x=x*(bb+c-1)%c;
  if(!x)x=c;
  printf("%d\n",(int)x);
}