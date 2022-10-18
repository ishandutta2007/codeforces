#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

#define FOR(i,n) for(i=0;i<n;i++)
#define MAXN 1000111

using namespace std;

int N,a[MAXN],b[MAXN],d[MAXN];;
int B[MAXN];

int get(int p){
  int left=0,right=N,middle;
  while(left<right){
    middle=(left+right+1)/2;
    if(d[middle]<p) right=middle-1;
    else left=middle;
  }
  return left;
}

void process(int x){
  int p=B[x]+1;
  d[get(p)+1]=p;
}

int main(int argc, char *argv[]){
  int i;
  scanf("%d",&N);
  FOR(i,N) scanf("%d",a+i);
  FOR(i,N) scanf("%d",b+i);
  FOR(i,N) B[b[i]]=i;
  d[0]=N;
  FOR(i,N) process(a[i]);
  i=0;
  while(d[i]) i++;
  printf("%d\n",i-1);
  return 0;
}