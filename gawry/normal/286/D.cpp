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
const int INF=1000000000;
const int MAX=100000+123;
int n,m,l[MAX],r[MAX],t[MAX],query[MAX];
typedef pair<int,int> p2;
typedef pair<p2,int> p3;
vector<p3> s;
void pre(){
  vector<p2> q;
  for(int i=1;i<=m;i++){
    q.push_back(p2(l[i],i));
    q.push_back(p2(r[i],-i));
  }
  sort(q.begin(),q.end());
  set<p2> active;
  int prev=-INF;
  for(int i=0;i<q.size();i++){
    int cur=q[i].first;
    if(prev<cur&&!active.empty()){
      s.push_back(p3(p2(prev,cur),active.begin()->first));
    }
    prev=cur;
    if(q[i].second>0){
      active.insert(p2(t[q[i].second],q[i].second));
    }else{
      active.erase(p2(t[-q[i].second],-q[i].second));
    }
  }
  //for(int i=0;i<s.size();i++)printf("%d,%d %d\n",s[i].first.first,s[i].first.second,s[i].second);
}
int a[MAX];
main(){
  scanf("%d %d",&n,&m);
  for(int i=1;i<=m;i++)scanf("%d %d %d",&l[i],&r[i],&t[i]);
  pre();
  for(int i=1;i<=n;i++)scanf("%d",&query[i]);
  vector<p3> q;
  for(int i=1;i<=n;i++)q.push_back(p3(p2(query[i],0),i));
  for(int i=0;i<s.size();i++){
    q.push_back(p3(p2(s[i].second-s[i].first.second,1),0));
    q.push_back(p3(p2(s[i].second-s[i].first.first,-1),0));
  }
  sort(q.begin(),q.end());
  int prev=-INF,ans=0,open=0;
  for(int i=0;i<q.size();i++){
    int cur=q[i].first.first;
    ans+=open*(cur-prev);
    //printf("%d %d :%d,%d\n",prev,cur,open,ans);
    prev=cur;
    if(q[i].first.second==0){
      a[q[i].second]=ans;
    }else open+=q[i].first.second;
  }
  for(int i=1;i<=n;i++)printf("%d\n",a[i]);
}