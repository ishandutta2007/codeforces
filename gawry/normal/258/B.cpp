#include<cstdio>
#include<cstring>
#include<iostream>
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

const int MOD=1000000007;
int f[20],m;
void calc(int left,int cur){//cout<<left<<" "<<cur<<endl;
  int t[20]={},tt[20];
  t[cur]=1;
  while(left--){
    memset(tt,0,sizeof(t));
    for(int i=0;i<15;i++)for(int next=0;next<=9;next++)tt[i+(next==4||next==7)]+=t[i];
    memcpy(t,tt,sizeof(t));
  }
  for(int i=0;i<20;i++)f[i]+=t[i];
}

int choose(int n,int k){
  if(k<0||k>n)return 0;
  long long ans=1;
  for(int i=0;i<k;i++)ans=ans*(n-i)%MOD;
  for(int i=1;i<=k;i++)ans=ans*inverse(i,MOD)%MOD;
  return ans;
}

main(){
  scanf("%d",&m);
  char buf[20];
  sprintf(buf,"%d",m+1);
  int len=strlen(buf);
  for(int i=1;i<len;i++)for(int first=1;first<=9;first++)calc(i-1,first==4||first==7);
  for(int i=0;i<len;i++)for(int next=0;next<buf[i]-'0';next++)if(i||next){
    int cnt=next==4||next==7;
    for(int j=0;j<i;j++)cnt+=buf[j]=='4'||buf[j]=='7';
    calc(len-i-1,cnt);
  }
//  for(int i=0;i<15;i++)cout<<i<<" "<<f[i]<<endl;
  int ans=0,t[150][7]={1},tt[150][7]; 
  for(int cnt=0;cnt<=10;cnt++){
    for(int i=0;i<cnt;i++)ans=(ans+(long long)f[cnt]*t[i][6])%MOD;
    memset(tt,0,sizeof(t));
    for(int i=0;i<80;i++)for(int j=0;j<=6;j++)for(int k=0;j+k<=6;k++)tt[i+k*cnt][j+k]=(tt[i+k*cnt][j+k]+(long long)t[i][j]*choose(f[cnt],k))%MOD;
    memcpy(t,tt,sizeof(t));
  }
  for(int i=1;i<=6;i++)ans=(long long)ans*i%MOD;
  printf("%d\n",ans);
}