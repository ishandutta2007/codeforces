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
const int MAX=1000123;
int n,k,a[MAX];
int grundy(int i){
  if(k%2==1){
    if(i<4)return i%2;
    if(i==4)return 2;
    if(i%2==1)return 0;
    return grundy(i/2)==1?2:1;
  }else{
    return i<3?i:1-i%2;
  }
}
int main(){
  scanf("%d %d",&n,&k);
  int ans=0;
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    ans^=grundy(a[i]);
  }
  printf("%s\n",ans?"Kevin":"Nicky");
  return 0;
}