#include<cstdio>
#include<vector>
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

const int MOD=1000000007;
#define MAX 110000
int n,t[MAX],cnt[MAX];
vector<int> d[MAX];
int f(vector<int> &x){
  int ans=1;
  for(int i=1;i<=x.size();i++){
    int left=cnt[x[i-1]]-(i==x.size()?cnt[MAX-1]:cnt[x[i]]);
    ans=(long long)ans*power(i,left,MOD)%MOD; 
  }
  return ans;
}
main(){
  for(int i=1;i<MAX;i++)for(int j=i;j<MAX;j+=i)d[j].push_back(i);
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf("%d",&t[i]);
  for(int i=0;i<n;i++)++cnt[t[i]];
  for(int i=MAX-1;i;i--)cnt[i-1]+=cnt[i];
  int ans=1;
  for(int m=2;m<MAX;m++){
    ans=(ans+f(d[m]))%MOD;
    d[m].pop_back();
    ans=(ans+MOD-f(d[m]))%MOD;
  }
  printf("%d\n",ans);
}