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
int n,m,x[110];
const int SCORE=100*1000+1234;
long double score[SCORE];
int main(){
  scanf("%d %d",&n,&m);
  int kleofas_score=0;
  for(int i=0;i<n;i++){
    scanf("%d",&x[i]);
    kleofas_score+=x[i];
  }
  if(m==1){
    printf("1\n");
    return 0;
  }
  score[0]=1.0;
  for(int i=0;i<n;i++){
    long double acc=0.0;
    for(int j=1;j<=m;j++)if(j<=kleofas_score){
      acc+=score[kleofas_score-j];
    }
    for(int j=kleofas_score-1;j>=0;j--){
      acc-=score[j];
      if(j-m>=0){
        acc+=score[j-m];
      }
      score[j]=(j>=x[i]?acc-score[j-x[i]]:acc)/(m-1);
    }
  }
  double ans=1.0;
  for(int i=0;i<kleofas_score;i++){
    ans+=score[i]*(m-1);
  }
  printf("%.9lf\n",ans);
  return 0;
}