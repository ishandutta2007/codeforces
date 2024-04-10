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
const int MAX=110000;
int n,m,a[MAX];
long long s[MAX],b[MAX];
typedef pair<long long,long long> p2;
bool useless(p2 a,p2 b,p2 c){
//  double x=(double)(b.second-a.second)/(a.first-b.first);
  return (long long)(b.first-c.first)*(b.second-a.second)>=(long long)(c.second-b.second)*(a.first-b.first);
}
void add(vector<p2> &res,p2 next){
  while(res.size()>=2&&useless(res[res.size()-2],res.back(),next)){
    res.pop_back();
  }
  res.push_back(next);
}
void build(vector<p2> &res,const vector<p2> &x,const vector<p2> &y){
  res.clear();
  int i=0,j=0;
  while(i<x.size()&&j<y.size()){
    if(x[i].first>y[j].first){
      add(res,x[i]);
      ++i;
    }else{
      add(res,y[j]);
      ++j;
    }
  }
  while(i<x.size()){
    add(res,x[i]);
    ++i;
  }
  while(j<y.size()){
    add(res,y[j]);
    ++j;
  }
}
long long eval(const vector<p2> &hull,long long x){
  long long ans=1ll<<60;
  if(hull.empty())return ans;
  int from=0,to=hull.size()-1;
  while(from+5<to){
    int from2=(2*from+to)/3,to2=(from+2*to)/3;
    long long left=(long long)hull[from2].first*x+hull[from2].second;
    long long right=(long long)hull[to2].first*x+hull[to2].second;
    if(left>right)from=from2;else to=to2;
  }
  while(from<=to){
    ans=min(ans,(long long)hull[from].first*x+hull[from].second);
    ++from;
  }
//  for(int i=0;i<hull.size();i++)ans=min(ans,(long long)hull[i].first*x+hull[i].second);
  return ans;
}
const int POWER=1<<17;
vector<p2> hull[2*POWER];
p2 q[MAX];
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  s[0]=0;
  for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
  for(int i=0;i<=n;i++)b[i]=-s[i]+(long long)i*a[i];
  for(int i=1;i<=n;i++)a[i]*=-1;
  for(int i=1;i<=n;i++)hull[POWER+i].push_back(make_pair(a[i],b[i]));
  for(int i=POWER-1;i>=1;i--)build(hull[i],hull[2*i],hull[2*i+1]);
  scanf("%d",&m);
  for(int i=1;i<=m;i++){
    int x,y;
    scanf("%d %d",&x,&y);
    q[i].first=y-x;
    q[i].second=y;
    //q[i].first=q[i].second-q[i].first;
  }
  for(int k=1;k<=m;k++){
    long long ans=1LL<<60;
    int i=q[k].first,j=q[k].second,x=q[k].first;
    i+=POWER;
    j+=POWER;
    ans=min(ans,eval(hull[i],x));
    ans=min(ans,eval(hull[j],x));
    while(i+1<j){
      if(i%2==0)ans=min(ans,eval(hull[i+1],x));
      if(j%2==1)ans=min(ans,eval(hull[j-1],x));
      i/=2;
      j/=2;
    }
/*    for(int jj=i;jj<=j;jj++){
      long long tmp=b[jj]+(long long)i*a[jj];
      ans=min(ans,tmp);
    }*/
    cout<<s[q[k].second]+ans<<endl;
  }
  return 0;
}