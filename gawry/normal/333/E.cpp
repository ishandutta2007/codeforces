#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cmath>
using namespace std;
int n,x[3010],y[3010];
pair<int,int> s[3010*3010/2];
int dist(int a,int b){
  return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
}
bool cmp(pair<int,int> a,pair<int,int> b){
  return dist(a.first,a.second)<dist(b.first,b.second);
}
bitset<3010> v[3010];
main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf("%d %d",&x[i],&y[i]);
  int cnt=0;
  for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)s[cnt++]=make_pair(i,j);
  sort(s,s+cnt,cmp);
  int ans=0;
  for(int i=cnt-1;i>=0;i--){
    int a=s[i].first,b=s[i].second;
    bitset<3010> tmp=v[a];
    tmp&=v[b];
    if(tmp.any()){
      ans=dist(a,b);
      break;
    }
    v[a].set(b);
    v[b].set(a);
  }
  printf("%.9lf\n",sqrt((double)ans)/2);
}