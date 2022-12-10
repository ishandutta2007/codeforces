#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>
using namespace std;
#define POWER (1<<18)
#define MAX 150000
int n,m,C,x[MAX],p[MAX];
double f[MAX],ans,maximum[2*POWER],minimum[2*POWER],best[2*POWER];
double calc(int from,int to){
  from+=POWER;to+=POWER;
  double ans=0;
  vector<int> left,right;
  left.push_back(from);
  right.push_back(to);
  while(from+1<to){
    if(from%2==0){
      ans=max(ans,best[from+1]);
      left.push_back(from+1);
    }
    if(to%2){
      ans=max(ans,best[to-1]);
      right.push_back(to-1);
    }
    from/=2;to/=2;
  }
  vector<int> all=left;
  all.insert(all.end(),right.rbegin(),right.rend());
  double tmp=-1e20;
  for(int i=all.size()-1;i>=0;i--){
    ans=max(ans,tmp-minimum[all[i]]);
    tmp=max(tmp,maximum[all[i]]);
  }
//  for(int i=0;i<all.size();i++)for(int j=i+1;j<all.size();j++)ans=max(ans,maximum[all[j]]-minimum[all[i]]);
  return ans;
}
main(){
  scanf("%d %d %d",&n,&m,&C);
  for(int i=0;i<n;i++)scanf("%d",&x[i]);
  for(int i=1;i<n;i++){scanf("%d",&p[i]);p[i]+=p[i-1];}
  for(int i=0;i<n;i++){
    f[i]=0.5*x[i]-0.01*C*p[i];
    minimum[POWER+i]=maximum[POWER+i]=f[i];
  }
  for(int i=POWER-1;i>=0;i--){
    maximum[i]=max(maximum[2*i],maximum[2*i+1]);
    minimum[i]=min(minimum[2*i],minimum[2*i+1]);
    best[i]=max(max(best[2*i],best[2*i+1]),maximum[2*i+1]-minimum[2*i]);
  }
  while(m--){
    int a,b;
    scanf("%d %d",&a,&b);
    --a;--b;
/*    double cur=-1e20;
    for(int c=a;c<=b;c++)for(int d=c;d<=b;d++)if(f[d]-f[c]>cur){
      cur=f[d]-f[c];
    }
printf("%.6lf %.6lf\n",cur,calc(a,b));
assert(cur==calc(a,b));*/
    ans+=calc(a,b);
  }
  printf("%.6lf\n",ans);
}