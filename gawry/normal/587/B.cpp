#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#include<cassert>
#include<iostream>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
const int MAX=1100000;
const int MOD=1000000000+7;
int n,k,a[MAX],s[MAX];
long long cur[MAX],len;
int main(){
  cin>>n>>len>>k;
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    s[i]=a[i];
  }
  sort(s,s+n);
  long long full=len/n;
  map<int,int> rem;
  for(int i=0;i<len%n;i++){
    ++rem[a[i]];
  }
  int ans=0;
  cur[0]=1;
  for(int i=0;i<n;i++)if(i+1==n||s[i]<s[i+1]){
    int cnt=1;
    while(i-cnt>=0&&s[i-cnt]==s[i]){
      ++cnt;
    }
    for(int j=1;j<=k;j++){
      cur[j]=(cur[j]+(long long)cur[j-1]*cnt)%MOD;
    }
    
    int last=rem[s[i]];
    for(int j=1;j<=k&&full>=j-1;j++){
      ans=(ans+(long long)cur[j-1]*last)%MOD;
    }
  }
  for(int j=1;j<=k&&full-j+1>=0;j++){
    ans=(ans+(long long)cur[j]*(full%MOD+MOD-j+1))%MOD;
  }
  printf("%d\n",ans);

  return 0;
}