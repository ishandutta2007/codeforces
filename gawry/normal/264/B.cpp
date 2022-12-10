#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int MAX=100000+7;
int n,a[MAX],d[MAX],r[MAX];
map<int,int> m;
main(){
  for(int i=2;i<MAX;i++)d[i]=i;
  for(int i=2;i<MAX;i++)if(d[i]==i)for(int j=2*i;j<MAX;j+=i)d[j]=i;
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf("%d",&a[i]);
  for(int i=0;i<n;i++){
    r[i]=1;
    int tmp=a[i];
    while(tmp>1){
      int cur_d=d[tmp];
      map<int,int>::iterator it=m.find(cur_d);
      if(it!=m.end())r[i]=max(r[i],1+it->second);
      while(tmp%cur_d==0)tmp/=cur_d;
    }
    tmp=a[i];
    while(tmp>1){
      int cur_d=d[tmp];
      m[cur_d]=max(m[cur_d],r[i]);
      while(tmp%cur_d==0)tmp/=cur_d;
    }
  }
  printf("%d\n",*max_element(r,r+n));
}