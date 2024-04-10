#include<cstdio>
#include<vector>
#include<map>
using namespace std;
int n,ans,t[4010];
typedef vector<int> vi;
main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf("%d",&t[i]);
  map<int,vi> mem;
  for(int i=0;i<n;i++)mem[t[i]].push_back(i);
  for(map<int,vi>::iterator it=mem.begin();it!=mem.end();it++)ans=max(ans,(int)it->second.size());
  for(map<int,vi>::iterator it=mem.begin();it!=mem.end();it++)
  for(map<int,vi>::iterator it2=mem.begin();it2!=it;it2++){
    vi tmp,&a=it->second,&b=it2->second;
    int i=0,j=0;
    while(i<a.size()||j<b.size()){
      if(j==b.size()||i<a.size()&&a[i]<b[j]){
				if(tmp.empty()||tmp.back())tmp.push_back(0);        
	      ++i;
      }else{
				if(tmp.empty()||!tmp.back())tmp.push_back(1);
        ++j;
      }
    }
		ans=max(ans,(int)tmp.size());
  }
  printf("%d\n",ans);
}