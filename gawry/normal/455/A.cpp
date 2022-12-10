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
const int MAX=1000000;
int n,cnt[MAX];
long long ans[MAX];
int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int x;
    scanf("%d",&x);
    ++cnt[x];
  }
  ans[0]=0;
  for(int i=1;i<MAX;i++){
    ans[i]=max((long long)i*cnt[i]+(i>=2?ans[i-2]:0),ans[i-1]);
  }
  cout<<ans[MAX-1]<<endl;
  return 0;
}