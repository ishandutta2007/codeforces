#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 210000
int n,t[MAX],s[2*MAX];
main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf("%d",&t[i]);
  sort(t,t+n);
  for(int i=0;i<n;i++)s[i]=t[i]-t[0],s[n+i]=t[n-1]-t[i];
  sort(s,s+2*n);
  int i=0,j=n-1;
  double r=1e20,x[3];
  for(int k=0;k<2*n;k++){
    int L=s[k];
    while(i<n&&t[i]<=t[0]+L)i++;
    while(j>=0&&t[n-1]-L<=t[j])j--;
    double rr=L;
    if(i<=j)rr=max(rr,(double)t[j]-t[i]);
    if(rr<r){
      r=rr;
      x[0]=t[0]+r/2;
      x[1]=t[n-1]-r/2;
      x[2]=i<=j?0.5*(t[j]+t[i]):t[0]+r/2;
    }
  }
  printf("%.6lf\n%.6lf %.6lf %.6lf\n",r/2,x[0],x[1],x[2]);
}