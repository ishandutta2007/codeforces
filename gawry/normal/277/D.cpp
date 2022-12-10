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
const int MAX=1000;
const long double EPS=1e-9;
const long double INF=1e9;
int n,t,scoreSmall[MAX],scoreLarge[MAX],timeSmall[MAX],timeLarge[MAX];
long double prob[MAX],score[2000],penalty[2000];
bool better(int x,int y){
  if(prob[y]+EPS<1&&prob[x]+EPS<1)return timeLarge[y]*prob[y]*(1-prob[x])<timeLarge[x]*prob[x]*(1-prob[y]);
  return prob[y]<prob[x];
}
main(){
  scanf("%d %d",&n,&t);
  for(int i=0;i<n;i++){
    double tmp;
    scanf("%d %d %d %d %lf",&scoreSmall[i],&scoreLarge[i],&timeSmall[i],&timeLarge[i],&tmp);
    prob[i]=tmp;
  }
  for(int i=0;i<n;i++){
    int j=i-1;
    while(j>=0&&better(j,j+1)){
      swap(scoreSmall[j],scoreSmall[j+1]);
      swap(scoreLarge[j],scoreLarge[j+1]);
      swap(timeSmall[j],timeSmall[j+1]);
      swap(timeLarge[j],timeLarge[j+1]);
      swap(prob[j],prob[j+1]);
      --j;
    }
  }
  score[0]=0;
  for(int i=1;i<=t;i++)score[i]=-INF;
  for(int i=0;i<n;i++)for(int j=t;j>=timeSmall[i];j--){
    long double old_score=score[j];

    score[j]=max(score[j],score[j-timeSmall[i]]+scoreSmall[i]);
    if(j>=timeLarge[i]+timeSmall[i]&&prob[i]+EPS<1){
      score[j]=max(score[j],score[j-timeLarge[i]-timeSmall[i]]+scoreLarge[i]*(1-prob[i])+scoreSmall[i]);
    }
  
    if(fabs(score[j]-old_score)>EPS)penalty[j]=INF;
    if(fabs(score[j]-(score[j-timeSmall[i]]+scoreSmall[i]))<EPS){
      penalty[j]=min(penalty[j],penalty[j-timeSmall[i]]+timeSmall[i]); 
    }
    if(j>=timeLarge[i]+timeSmall[i]&&fabs(score[j]-(score[j-timeLarge[i]-timeSmall[i]]+scoreLarge[i]*(1-prob[i])+scoreSmall[i]))<EPS&&prob[i]+EPS<1){
      long double tmp=(penalty[j-timeLarge[i]-timeSmall[i]]+timeSmall[i])*prob[i]+j*(1-prob[i]);
     // printf("%d,%d %.6lf %.6lf\n",i,j,score[j],tmp);
      penalty[j]=min(penalty[j],tmp); 
    }
  }
  int best=0;
  for(int i=0;i<=t;i++)if(score[i]>score[best]||fabs(score[i]-score[best])<EPS&&penalty[i]<penalty[best])best=i;
  printf("%.9lf %.9lf\n",(double)score[best],(double)penalty[best]);
}