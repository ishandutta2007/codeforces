#include<cstdio>
#include<algorithm>
#include<numeric>
#include<cstring>
using namespace std;
typedef long long int64;

int64 power(int64 x,int64 k,int64 p) {
  int r=1;
  while (k) {
    if (k&1)
      r=((int64)r*x)%p;
    k>>=1;
    x=((int64)x*x)%p;
  }
  return r;
}

int64 alfa,beta;

int64 gcd(int64 a,int64 b) {
  if (!b) {
    alfa=1;
    beta=0;
    return a;
  }
  int64 d=gcd(b,a%b),z=beta;
  //alfa*b+(a-a/b*b)*beta=beta*a+(alfa-a/b*beta)*b
  beta=alfa-a/b*beta;
  alfa=z;
  return d;
}

int64 inverse(int64 a,int64 n) {
  gcd(a,n);
  return (n+alfa%n)%n;
}
#define MOD 1000000007
int n,x[110],y[110],mem[110][1100],choose[1100][1100];
int calc(int next,int additional){
  if(next==n)return !additional;
  additional+=x[next];
  if(mem[next][additional]>-1)return mem[next][additional];
  int r=0;
  for(int take=0;take<=additional&&take<=y[next];take++)r=(r+(int64)calc(next+1,additional-take)*choose[additional][take])%MOD;
//  printf("%d %d : %d\n",next,additional,r);
  return mem[next][additional]=r;
}
main(){
  for(int i=0;i<1100;i++){choose[i][0]=1;for(int j=0;j<i;j++)choose[i][j+1]=(choose[i-1][j]+choose[i-1][j+1])%MOD;}
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf("%d",&x[i]);
  for(int i=0;i<n;i++)scanf("%d",&y[i]);
  memset(mem,-1,sizeof(mem));
  int r=calc(0,0);
//  printf("%d\n",r);
//  for(int i=0;i<n;i++)for(int j=1;j<=x[i];j++)r=(int64)r*inverse(j,MOD)%MOD;
  int total=accumulate(x,x+n,0);
  for(int i=0;i<n;i++){
    r=(int64)r*choose[total][x[i]]%MOD;
    total-=x[i]; 
  }
  printf("%d\n",r);
}