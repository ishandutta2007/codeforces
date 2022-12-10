#include<cstdio>
#include<algorithm>
using namespace std;
int n,c[410],t[410],sol;
void greedy(int x){
  for(int i=0;i<n;i++){
    t[i]=x/c[i];
    x%=c[i]; 
  } 
}
int calc(){
  int r=0;
  for(int i=0;i<n;i++)r+=t[i];  
  return r; 
}
#define INF 2100000000
main(){
  scanf("%d",&n);
  sol=INF;
  for(int i=0;i<n;i++)scanf("%d",&c[i]);
  for(int i=1;i<n;i++)for(int j=0;j<n;j++){
    greedy(c[i-1]-1);
    t[j]++;
    for(int k=j+1;k<n;k++)t[k]=0;
    int cost=calc(),s=0;
    for(int k=0;k<n;k++)s+=t[k]*c[k];
    greedy(s);
    if(calc()>cost)sol=min(sol,s);
  }
  printf("%d\n",sol<INF?sol:-1);
}