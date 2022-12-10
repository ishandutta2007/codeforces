#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAX=1010;
const long double pi=2*acos(0.0);
int n,k,x[MAX],y[MAX],r[MAX];
typedef pair<long double,long double> p2;
int calc(vector<p2> t){
  typedef pair<long double,int> event;
  vector<event> s;
  for(int i=0;i<t.size();i++){
    s.push_back(event(t[i].first+1e-6,1));
    s.push_back(event(t[i].second,-1));
  }
  int cur=0,ans=0;
  sort(s.begin(),s.end());
  for(int i=0;i<s.size();i++){
    cur+=s[i].second;
    ans=max(ans,cur);
  }
  return ans;
}
main(){
  scanf("%d %d",&n,&k);
  for(int i=0;i<n;i++)scanf("%d %d %d",&x[i],&y[i],&r[i]);
  long long ans=0;
  for(int i=0;i<n;i++){
    vector<p2> t;
//    cout<<i<<endl;
    for(int j=0;j<n;j++)if(i!=j){
      long double angle=atan2(y[j]-y[i],x[j]-x[i]);
//      if(angle<0)angle+=2*pi;
      long double dist=hypot(x[i]-x[j],y[i]-y[j]);
      long double alfa=acos((r[i]-r[j])/dist);
      long double a=dist*r[i]/(r[i]+r[j]);
      long double beta=acos(r[i]/a);

//      cout<<angle<<" "<<alfa<<" "<<beta<<endl;
      t.push_back(p2(angle-alfa,angle-beta));
      t.push_back(p2(angle+beta,angle+alfa));
      t.push_back(p2(2*pi+angle-alfa,2*pi+angle-beta));
      t.push_back(p2(2*pi+angle+beta,2*pi+angle+alfa));
    }
    int cur=calc(t);
 //   cout<<cur<<endl;
    ans=max(ans,n+(long long)k*(cur+cur+k+1)/2);
  }
  cout<<ans<<endl;
}