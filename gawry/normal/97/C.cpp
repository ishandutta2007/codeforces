#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int n;
double p[110];
main(){
  scanf("%d",&n);
  for(int i=0;i<=n;i++)scanf("%lf",&p[i]);
  double ans=p[0];
  for(int i=1;i<=n;i++){
    double x=min(1.0,0.5*n/i);
    ans=max(ans,x*p[i]);
  }
  for(int i=0;i<=n;i++)for(int j=i+1;j<=n;j++){
    double x=(double)(j-0.5*n)/(j-i);
    if(x<0)continue;
    if(x>1)continue;
//    cout<<x*p[i]+(1-x)*p[j]<<"   "<<i<<" "<<j<<"    "<<x<<endl;
    ans=max(ans,x*p[i]+(1-x)*p[j]);
  }
  printf("%.6lf\n",ans);
}