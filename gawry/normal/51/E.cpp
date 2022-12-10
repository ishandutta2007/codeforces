#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 710
int t[MAX][MAX],t2[MAX][MAX],t3[MAX][MAX],n,m,d[MAX];
main(){
  scanf("%d %d",&n,&m);  
  while(m--){
    int a,b;
    scanf("%d %d",&a,&b);
    --a;--b;
    t[a][b]=t[b][a]=1;
    ++d[a];++d[b];
  }
  for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
    int s=0;
    for(int k=0;k<n;k++)s+=t[i][k]*t[k][j];
    t2[j][i]=t2[i][j]=s;
  }
  for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
    int s=0;
    for(int k=0;k<n;k++)if(k!=i&&k!=j)s+=t[i][k]*(t2[k][j]-t[i][j]);
    t3[j][i]=t3[i][j]=s;
  }
  long long r=0;
  for(int i=0;i<n;i++)for(int j=0;j<n;j++){
    r+=(long long)t2[i][j]*t3[i][j];
  }
  for(int i=0;i<n;i++)for(int j=0;j<n;j++){
    r-=(long long)t2[i][j]*t[i][j]*(d[i]-2+d[j]-2);
  }
  cout<<r/10<<endl;
}