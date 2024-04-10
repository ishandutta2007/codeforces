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
const int MAX=2000000;
int n,cnt[MAX];
int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int x;
    scanf("%d",&x);
    ++cnt[x];
  }
  int ans=0;
  for(int i=0;i+1<MAX;i++){
     cnt[i+1]+=cnt[i]/2;
     ans+=cnt[i]%2;
  }
  printf("%d\n",ans);
  return 0;
}