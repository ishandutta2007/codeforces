#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
using namespace std;
int g[5010],next,seen[6010];
char t[5010];
int f(int from,int to){
  if(to<from)return 0;
  int r=0;
  int cur=0;
  for(int i=from+1;i<to;i++)if(t[i-1]==t[i+1]){
    ++cur;
  }else{
    r^=g[cur];
    cur=0;
  }
  return r^g[cur];
}
main(){
  for(int i=1;i<5010;i++){
    ++next;
    for(int j=0;j<i;j++)seen[g[max(0,j-1)]^g[max(0,i-j-2)]]=next;
    g[i]=0;
    while(seen[g[i]]==next)++g[i];
//    printf("%d -> %d\n",i,g[i]);
  }
  scanf("%s",t);
  int n=strlen(t);
  if(!f(0,n-1)){
    puts("Second");
  }else{
    int i=1;
    while(i+1<n&&(t[i-1]!=t[i+1]||f(0,i-1)!=f(i+1,n-1)))++i;
    assert(i+1<n);
    puts("First");
    printf("%d\n",i+1);
  }
}