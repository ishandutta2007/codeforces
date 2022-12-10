#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

const int MAX=110000;
int n,a[MAX];
int64 s[MAX],ans=(1LL<<62)-1;
inline void check(int64 i,int64 j){
  ans=min(ans,(i-j)*(i-j)+(s[i]-s[j])*(s[i]-s[j]));
}
typedef pair<int,int> p2;
set<p2> q;
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  s[0]=0;
  for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
  //q.insert(p2(s[0],0));
  for(int i=1,j=0;i<=n;i++){
    while(((i-j)*(i-j)>=ans)){
      q.erase(p2(s[j],j));
      ++j;
    }
    set<p2>::iterator it=q.lower_bound(p2(s[i],-1));
    while(it!=q.end()&&(it->first-s[i])*(it->first-s[i])<ans){
      check(it->second,i);
      ++it;
    }
    it=q.lower_bound(p2(s[i],-1));
    while(it!=q.begin()){
      --it;
      if((it->first-s[i])*(it->first-s[i])>=ans)break;
      check(it->second,i);
    }
    q.insert(p2(s[i],i));
  }
  cout<<ans<<endl;
  return 0;
}