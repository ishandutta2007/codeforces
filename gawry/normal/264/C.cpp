#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cassert>
using namespace std;
const int MAX=100000+7;
const long long INF=1LL<<60;
int n,q,v[MAX],c[MAX],a,b;
long long r[MAX],cur[MAX];
long long calc(){
  for(int i=1;i<=n;i++)cur[i]=-INF;
  int first=n,second=n+1;
  r[n]=r[n+1]=0;
  c[n]=0;
  c[n+1]=-1;
  for(int i=n-1;i>=0;i--){
    long long other=c[i]==c[first]?r[second]:r[first];
    long long start=(long long)b*v[i]+max(cur[c[i]],other);
    r[i]=start;
    long long cont=(long long)a*v[i]+max(cur[c[i]],other); 
    cur[c[i]]=max(cur[c[i]],cont);
    if(r[i]>r[first]){
      if(c[i]!=c[first])second=first;
      first=i;
    }else if(c[first]!=c[i]&&r[i]>r[second]){
      second=i;
    }
  }
  return *max_element(r,r+n+1);
}
main(){
  scanf("%d %d",&n,&q);
  for(int i=0;i<n;i++)scanf("%d",&v[i]);
  for(int i=0;i<n;i++)scanf("%d",&c[i]);
  for(int i=0;i<n;i++)assert(1<=c[i]&&c[i]<=n);
  while(q--){
    scanf("%d %d",&a,&b);
    cout<<calc()<<endl;
  }
}