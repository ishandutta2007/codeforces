/* Writen by Filip Hlasek 2011 */
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

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

int main(int argc, char *argv[]){
  int n;
  scanf("%d",&n);
  long long resmin = 1000000000000000000LL, resmax = 0;
  for(long long a=1; a*a*a <= n; a++){
    if(n%a==0){
      for(long long b=a; a*b*b <= n; b++){
        if((n/a)%b==0){
          long long c=n/a/b;
          resmin = min(resmin, (a+1)*(b+2)*(c+2) - n);
          resmin = min(resmin, (a+2)*(b+1)*(c+2) - n);
          resmin = min(resmin, (a+2)*(b+2)*(c+1) - n);
          resmax = max(resmax, (a+1)*(b+2)*(c+2) - n);
          resmax = max(resmax, (a+2)*(b+1)*(c+2) - n);
          resmax = max(resmax, (a+2)*(b+2)*(c+1) - n);
        }
      }
    }
  }
  cout << resmin << " " << resmax << endl;
  return 0;
}