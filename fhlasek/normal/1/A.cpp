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

using namespace std;

int main(int argc, char *argv[]){
  int N,M,A;
  scanf("%d%d%d",&N,&M,&A);
  cout << (long long)((N-1)/A+1)*((M-1)/A+1) << endl;
  return 0;
}