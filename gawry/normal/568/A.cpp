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
const int MAX=10000000;
bool prime[MAX];
char s[100];
bool palindrome(int x){
  int len=0;
  while(x){
    s[len++]=x%10+'0';
    x/=10;
  }
  for(int i=0;i<len/2;i++)if(s[i]!=s[len-1-i]){
    return false;
  }
  return true;
}
int main(){
  int p,q;
  cin>>p>>q;
  prime[1]=false;
  for(int i=2;i<MAX;i++){
    prime[i]=true;
  }
  for(int i=2;i<MAX;i++)if(prime[i])for(int j=2*i;j<MAX;j+=i){
    prime[j]=false;
  }
  int n=1;
  long long left=0,right=0;
  for(int i=1;i<MAX;i++){
    left+=prime[i];
    right+=palindrome(i);
    if(left*q<=right*p){
      n=i;
    }
  }
  printf("%d\n",n);
  return 0;
}