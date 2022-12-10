#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 1100000
#define POWER (1<<20)
int n,m,a[MAX],p[MAX];
typedef pair<int,int> p2;
p2 r[MAX];
double t[2*POWER];
double get(int x){
  x+=POWER;
  double ans=0;
  while(x){
    ans+=t[x];
    x/=2;
  }
  return ans;
}
void add(int x,int y,double delta){
  x+=POWER;
  y+=POWER;
  t[x]+=delta;
  if(x<y)t[y]+=delta;
  while(x+1<y){
    if(x%2==0)t[x+1]+=delta;
    if(y%2)t[y-1]+=delta;
    x/=2;
    y/=2;
  }
}
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
void join(int x,int y){
  x=find(x);
  y=find(y);
  if(x==y)return;
  p[x]=y;
  r[y]=p2(min(r[x].first,r[y].first),max(r[x].second,r[y].second));
}
main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf("%d",&a[i]);
  typedef pair<int,int> p2;
  vector<p2> s;
  for(int i=0;i<n;i++)s.push_back(p2(a[i],i));
  sort(s.begin(),s.end());
  for(int i=0;i<n;i++)p[i]=-1;
  for(int i=s.size()-1;i>=0;i--){
    int x=s[i].second;
    p[x]=x;
    r[x]=p2(x,x);
    int left=0,right=0; 
    if(x&&p[x-1]>=0){
      left=x-r[find(x-1)].first;
    }
    if(x+1<n&&p[x+1]>=0){
      right=r[find(x+1)].second-x;
    }
    if(left>right)swap(left,right);
    for(int j=0;j<=left;j++){
      add(j+1,j+right+1,s[i].first);
    }
    if(x&&p[x-1]>=0)join(x-1,x);
    if(x+1<n&&p[x+1]>=0)join(x,x+1);
  }
  scanf("%d",&m);
  for(int i=0;i<m;i++){
    int tmp;
    scanf("%d",&tmp);
    printf("%0.9lf\n",get(tmp)/(n-tmp+1));
  }
}