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

char a[101],b[101];

int main(int argc, char *argv[]){
  int A,B;
  int i;
  scanf("%s",a);
  for(A=0;a[A]!='\0';A++);
  scanf("%s",b);
  for(B=0;b[B]!='\0';B++);
  if(A!=B){ printf("NO\n"); return 0; }
  FOR(i,A) if(a[i]!=b[B-i-1]){ printf("NO\n"); return 0; }
  printf("YES\n");
  return 0;
}