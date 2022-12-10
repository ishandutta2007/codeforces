#include<vector>
#include<cstdio>
#include<map>
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
#define MAX 101000
int n,k,a[MAX];
bool lucky(int x){
  while(x){
    if(x%10!=4&&x%10!=7)return false;
    x/=10;
  }
  return true;
}
int choose[MAX],x[2000][2000];
main(){
  scanf("%d %d",&n,&k);
  for(int i=0;i<n;i++)scanf("%d",&a[i]);
  int nonlucky=0;
  map<int,int> cnt;
  for(int i=0;i<n;i++)if(lucky(a[i]))++cnt[a[i]];else ++nonlucky;
  choose[0]=1;
  for(int i=1;i<=nonlucky;i++){
    choose[i]=(int64)choose[i-1]*(nonlucky-i+1)%MOD*inverse(i,MOD)%MOD;
  }
  vector<int> take;
  for(map<int,int>::iterator it=cnt.begin();it!=cnt.end();it++)take.push_back(it->second);
  int r=0;
  for(int i=0;i<2000;i++)x[take.size()][i]=nonlucky-k+i>=0?choose[nonlucky-(k-i)]:0;
  for(int i=take.size()-1;i>=0;i--)for(int j=0;j<1234;j++){
    x[i][j]=(x[i+1][j]+(long long)x[i+1][j+1]*take[i])%MOD;
  }
  printf("%d\n",x[0][0]);
}