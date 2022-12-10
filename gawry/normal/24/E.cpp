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
#include<queue>
#include<cassert>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0; i<(int)(n); i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
typedef vector<int> vi;
typedef long long int64;

int64 det(int x0,int y0,int x1,int y1) {
  return (int64)x0*y1-(int64)y0*x1;
}
typedef pair<int,int> p2;
bool going_left(const p2 &a,const p2 &b,const p2 &c) {
  return det(a.first-b.first,a.second-b.second,c.first-b.first,c.second-b.second)<=0;
}
#define MAX 510000
int n,x[MAX],v[MAX];
double eval(const p2 &a,const p2 &b){
  return (double)(b.first-a.first)/(a.second-b.second); 
}
vector<p2> t;
main() {
  scanf("%d",&n);
  FOR(i,n)scanf("%d %d",&x[i],&v[i]);
  double r=1e20;
  FOR(i,n)if(v[i]>0){
    p2 next(x[i],v[i]);
    while(t.size()>1&&going_left(t[t.size()-2],t[t.size()-1],next))t.pop_back();
    t.push_back(next);
  }else if(!t.empty()){
    p2 next(x[i],v[i]);
    int from=0,to=t.size()-1;
    while(from+10<to){
      int middle1=(2*from+to)/3,middle2=(from+2*to)/3; 
      if(eval(t[middle1],next)<eval(t[middle2],next))to=middle2;else from=middle1;
    }
    while(from<=to)r=min(r,eval(t[from++],next));
  }
  if(r<1e20)printf("%.12lf\n",r);else puts("-1");
}