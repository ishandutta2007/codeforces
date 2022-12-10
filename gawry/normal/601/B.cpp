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
const int MAX=101000;
int n,a[MAX],d[MAX];
int calc(int i,int j){
  int p=abs(a[i]-a[j]);
  int q=abs(i-j);
  return (p+q-1)/q;
}
int pred[MAX],succ[MAX];
int main(){
  int q;
  scanf("%d %d",&n,&q);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(int i=1;i<n;i++){
    d[i]=calc(i-1,i);
  }
  vector<int> s;
  for(int i=1;i<n;i++){
    while(s.size()&&d[i]>=d[s.back()]){
      s.pop_back();
    }
    pred[i]=s.empty()?-1:s.back();
    s.push_back(i);
  }
  s.clear();
  for(int i=n-1;i>=1;i--){
    while(s.size()&&d[i]>d[s.back()]){
      s.pop_back();
    }
    succ[i]=s.empty()?n+10:s.back();
    s.push_back(i);
  }
  for(int i=0;i<q;i++){
    int from,to;
    scanf("%d %d",&from,&to);
    --from;--to;
    vector<int> up,down;
    long long ans=0;
    for(int pos=from+1;pos<=to;pos++){
      int x=max(pred[pos],from);
      int y=min(succ[pos],to+1);
      ans+=(long long)d[pos]*(pos-x)*(y-pos);
    }
    cout<<ans<<endl;
  }
  return 0;
}