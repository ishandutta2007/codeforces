#include<cassert>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[160],m[160][160],m2[160][160][160],m3[160][160];
char s[160];
int calc(int,int);
int choose(int,int,int);
#define INF 1000000000
int calc2(int from,int to){
  assert(from<=to);
  if(m3[from][to]>-2*INF)return m3[from][to];
  int ans=choose(from,to,0);
  for(int middle=from;middle<to;middle++)ans=max(ans,calc2(from,middle)+calc2(middle+1,to));
  return m3[from][to]=ans;
}
int choose(int from,int to,int taken){
  assert(from<=to);
  if(m2[from][to][taken]>-2*INF)return m2[from][to][taken];
  int ans=-INF;
  if(taken)ans=max(ans,a[taken]+calc2(from,to));
  if(from==to)ans=max(ans,a[taken+1]);
  if(from+1==to&&s[from]==s[to])ans=max(ans,a[taken+2]);
  for(int from2=from+1;from2<=to;from2++)ans=max(ans,calc2(from,from2-1)+choose(from2,to,taken));
  for(int to2=to-1;to2>=from;to2--)ans=max(ans,choose(from,to2,taken)+calc2(to2+1,to));
  if(from+1<to&&s[from]==s[to])ans=max(ans,choose(from+1,to-1,taken+2));
//printf("%d %d %d: %d\n",from,to,taken,ans);
  return m2[from][to][taken]=ans;
}
int calc(int from,int to){
  assert(from<=to);
  if(m[from][to]>-2*INF)return m[from][to];
  int ans=max(0,choose(from,to,0));
  for(int middle=from;middle<to;middle++)ans=max(ans,calc(from,middle)+calc(middle+1,to));
  return m[from][to]=ans;
}
main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
    if(a[i]==-1)a[i]=-INF;
  }
  scanf(" %s",s);
  memset(m,-120,sizeof(m));
  memset(m2,-120,sizeof(m2));
  memset(m3,-120,sizeof(m3));
  printf("%d\n",calc(0,n-1));
}