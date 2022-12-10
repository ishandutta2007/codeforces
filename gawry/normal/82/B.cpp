#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef vector<int> vi;
map<int,vi> where;
main(){
  int n,k,x;
  scanf("%d",&n);
  for(int i=0;i<n;i++)for(int j=0;j<i;j++){
   scanf("%d",&k);
    while(k--){
      scanf("%d",&x);
      where[x].push_back(i*n+j);
    }
  }
  map<vi,vi> t;
  for(map<int,vi>::iterator iter=where.begin();iter!=where.end();iter++)t[iter->second].push_back(iter->first);
  vi a[210];
  int next=0;
  for(map<vi,vi>::iterator iter=t.begin();iter!=t.end();iter++){
    a[next++]=iter->second;
  }
  if(!a[1].size()){
    a[1].push_back(a[0].back()); 
    a[0].pop_back();
  }
  for(int i=0;i<n;i++){
    printf("%d",a[i].size());
    for(int j=0;j<a[i].size();j++)printf(" %d",a[i][j]);
    puts(""); 
  }
}