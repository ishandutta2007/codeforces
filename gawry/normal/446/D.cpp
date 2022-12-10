#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#include<cassert>
#include<iostream>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
int n,m,k,trap[510];
int e[510][510];
long double t[510][510];
const long double EPS=1e-9;
void mult(long double a[110][110],long double b[110][110],long double c[110][110]){
  long double r[110][110]={};
  FOR(i,110)FOR(j,110)FOR(k,110)r[i][k]+=a[i][j]*b[j][k];
  FOR(i,110)FOR(j,110)c[i][j]=r[i][j];
}
int main(){
  scanf("%d %d %d",&n,&m,&k);
  for(int i=0;i<n;i++)scanf("%d",&trap[i]);
  while(m--){
    int x,y;
    scanf("%d %d",&x,&y);
    --x;--y;
    ++e[x][y];
    ++e[y][x];
  }
  for(int i=0;i<n;i++)if(!trap[i]){
    int deg=0;
    for(int j=0;j<n;j++)deg+=e[i][j];
    for(int j=0;j<n;j++)t[i][j]-=(long double)e[i][j]/deg;
    t[i][i]+=1.0;
  }else{
    t[i][i]=1.0;
  }
//for(int i=0;i<n;i++){
 // for(int j=0;j<n;j++)printf("%.6lf ",t[i][j]);
//  puts("");
//}
  for(int i=0;i<n;i++)if(!trap[i]){
    int j=i;
    for(int k=i;k<n;k++)if(abs(t[k][i])>abs(t[j][i]))j=k;
    for(int k=0;k<n;k++)swap(t[i][k],t[j][k]);
    double scale=t[i][i];
    for(int k=0;k<n;k++)t[i][k]/=scale;
    for(int j=0;j<n;j++)if(j!=i){
      scale=t[j][i];
      for(int k=0;k<n;k++)t[j][k]-=t[i][k]*scale;
    }
  }
  for(int i=0;i<n;i++)if(trap[i])t[i][i]=-1.0;
 // puts("");
 // for(int i=0;i<n;i++){
 //   for(int j=0;j<n;j++)if(trap[j])printf("%.4lf ",t[i][j]);
 //   printf("\n");
//  }
  long double m[110][110]={},v[510][510]={},r[110][110]={};
  int nr[510],next=0;
  for(int i=0;i<n;i++)if(trap[i])nr[i]=next++;
  for(int i=0;i<n;i++)if(trap[i]){
    int deg=0;
    for(int j=0;j<n;j++)deg+=e[i][j];
    for(int j=0;j<n;j++)for(int k=0;k<n;k++)v[i][k]-=t[j][k]/deg*e[i][j];
    for(int j=0;j<n;j++)if(trap[j])m[nr[i]][nr[j]]=v[i][j];
  }
  //for(int i=0;i<next;i++){
  //  for(int j=0;j<next;j++)printf("%.6lf ",m[i][j]);
  //  puts("");
 // }
  for(int i=0;i<next;i++)r[i][i]=1.0;
  k-=2;
  while(k){
    if(k&1)mult(m,r,r);
    mult(m,m,m);
    k/=2;
  }
  //for(int i=0;i<next;i++){
  //  for(int j=0;j<next;j++)printf("%.6lf ",r[i][j]);
  //  puts("");
 // }
  long double ans=0.0;
  for(int i=0;i<n;i++)if(trap[i]){
   // printf("-> %.6lf %.6lf\n",-t[0][i],r[nr[i]][next-1]);
    ans+=-t[0][i]*r[nr[i]][next-1];
  }
  printf("%.9lf\n",(double)ans);
  return 0;
}