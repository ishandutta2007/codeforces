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

using namespace std;

char names[5][20]={"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main(int argc, char *argv[]){
  int i=0,N,k=1;
  scanf("%d",&N);
  N--;
  while((long long)N>=5*(long long)k){
    N-=5*k;
    k*=2;
  }
  printf("%s\n",names[N/k]);
  return 0;
}