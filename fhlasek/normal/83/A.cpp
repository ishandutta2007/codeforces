#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>

#define FOR(i,n) for(i=0;i<n;i++)
#define MAXN 111111

using namespace std;

int N,a[MAXN];

int main(int argc, char *argv[]){
  long long res=0;
  int i,c=1;
  scanf("%d",&N);
  FOR(i,N) scanf("%d",a+i);
  for(i=1;i<N;i++){
    if(a[i]==a[i-1]) c++;
    else{ res+=(long long) c*(c+1)/2; c=1; }
  }
  res+=(long long) c*(c+1)/2;
  cout << res << endl;
  return 0;
}