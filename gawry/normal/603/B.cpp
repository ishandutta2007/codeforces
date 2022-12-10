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
int p,k;
const int MOD=1000000000+7;
long long power(long long x,long long n,long long mod){
  long long ans=1;
  while(n){
    if(n%2){
      ans=ans*x%mod;
    }
    x=x*x%mod;
    n/=2;
  }
  return ans;
}
int main(){
  cin>>p>>k;
  if(k==0){
    cout<<power(p,p-1,MOD)<<endl;
  }else if(k==1){
    cout<<power(p,p,MOD)<<endl;
  }else{
    long long cur=1;
    int cnt=0;
    do{
      ++cnt;
      cur=cur*k%p;
    }while(cur!=1);
    //cout<<(p-1)%cnt<<endl;
    cout<<power(p,(p-1)/cnt,MOD)<<endl;
  }
  return 0;
}