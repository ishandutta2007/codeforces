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
#include<queue>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
int n;
int main(){
  scanf("%d",&n);
  priority_queue<int64> q;
  for(int i=0;i<n;i++){
    int x;
    scanf("%d",&x);
    q.push(x);
  }
  int64 ans=0;
  while(q.size()>=2){
    int64 x=q.top();
    q.pop();
    int64 y=q.top();
    q.pop();
    ans+=x+y;
    q.push(x+y);
  }
  ans+=q.top();
  cout<<ans<<endl;
  return 0;
}