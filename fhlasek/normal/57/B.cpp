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
#define MAXM 111111

using namespace std;

int N,M,K;
int a[MAXM],b[MAXM],c[MAXM];

int main(int argc, char *argv[]){
  scanf("%d%d%d",&N,&M,&K);
  int i,j,k;
  FOR(i,M) scanf("%d%d%d",a+i,b+i,c+i);
  long long sum=0;
  FOR(i,K){
    scanf("%d",&k);
    FOR(j,M){ if(k>=a[j]&&k<=b[j]) sum+=c[j]+(k-a[j]); }
  }
  cout << sum << endl;
  return 0;
}