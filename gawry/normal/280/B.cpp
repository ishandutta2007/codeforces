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
const int MAX=100000;
int n,a[MAX];
main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf("%d",&a[i]);
  int ans=0;
  vector<int> q;
  for(int i=0;i<n;i++){
    while(!q.empty()&&q.back()<a[i])q.pop_back();
    if(!q.empty())ans=max(ans,a[i]^q.back());
    q.push_back(a[i]);
  }
  q.clear();
  for(int i=n-1;i>=0;i--){
    while(!q.empty()&&q.back()<a[i])q.pop_back();
    if(!q.empty())ans=max(ans,a[i]^q.back());
    q.push_back(a[i]);
  }
  printf("%d\n",ans);
}