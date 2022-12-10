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
long long n,m,k,ans=-1;
void check(long long x){
//  cout<<x<<endl;
  long long tmp=(n/(x+1))*(m/(k+1-x));
  if(ans==-1||tmp>ans)ans=tmp;
}
int main(){
  cin>>n>>m>>k;
  // x k-x
  // 0<=x<n
  // 0<=k-x<m
  // max(0,m-k+1)<=x<=min(k,n-1) 
  long long from=max(0LL,k-m+1),to=min(k,n-1);
  if(from<=to){
    check(from);
    check(to);
    long double z=m/n;
    long long tmp2=(k+1-z)/(z+1);
    for(long long tmp3=max(from,tmp2-1000000);tmp3<=min(to,tmp2+1000000);tmp3++)check(tmp3);
  }
  cout<<ans<<endl;
  return 0;
}