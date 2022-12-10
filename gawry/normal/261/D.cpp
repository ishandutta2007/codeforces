#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cstdlib>
using namespace std;
int k,n,maxb,t,b[100000],len,ends[100000],cnt,prev[100001];
main(){
  scanf("%d %d %d %d",&k,&n,&maxb,&t);
  len=(int)min((long long)n*maxb,(long long)n*t);
  while(k--){
    for(int i=0;i<n;i++)scanf("%d",&b[i]);
    cnt=0;
    for(int i=0;i<=maxb;i++)prev[i]=0;
    for(int i=0;i<len;i++){
      int val=b[i%n];
      if(!cnt||val>ends[cnt-1]){
        ends[cnt]=val;
        prev[val]=cnt;
        ++cnt;
      }else{
        while(ends[prev[val]]<val)++prev[val];
        ends[prev[val]]=val;
      }
    }
    printf("%d\n",cnt);
  }
}