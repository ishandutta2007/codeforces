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
int n,m;
const int MAX=1234567;
long double s[MAX];
long double choose(int n,int k){
  if(k<0||k>n)return 0.0;
  return s[n]-s[k]-s[n-k];


  double ans=1.0;
  for(int i=1;i<=k;i++)ans=ans*(n+1-i)/i;
  return ans;
}
int main(){
  for(int i=1;i<MAX;i++)s[i]=s[i-1]+log(i);
  cin>>n>>m;
  long double ans=0.0;
  for(int i=1;i<=min(n,m);i++){
    ans+=exp(choose((n-1)*m,n-i)+choose(m,i)-choose(n*m,n))*i*i/n;
//    cout<<i<<"="<<choose((n-1)*m,n-i)+choose(m,i)-choose(n*m,n)<<endl;
  }
  printf("%.9lf\n",(double)ans);
  return 0;
}