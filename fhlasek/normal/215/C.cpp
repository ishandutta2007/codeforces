/* Writen by Filip Hlasek 2012 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

int N, M, S; 
long long get(int n, int m){
  if(2*n + 1 > N || 2*m + 1 > M) return 0;
  return (N - 2*n) * (M - 2*m);
}

int main(int argc, char *argv[]){
  scanf("%d%d%d", &N, &M, &S);
  long long ans = 0;
  for(int a = 0; 2*a + 1 <= N; a++) for(int b = 0; 2*b + 1 <= M; b++) for(int c = 0; 2*c + 1 <= N; c++){
    int area = (2 * a + 1)  * (2 * b + 1);
    if(area > S) continue;
    if(c <= a){
      if(area == S) ans += (b + 1) * get(a, b);
      else if((S - area) % (2 * c + 1) == 0){
        int tmp = (S - area) / (2 * c + 1);
        if(tmp % 2 == 0) ans += get(a, (tmp + 2*b) / 2);
      }
    }
    else{
      if(S % (2*c + 1) == 0 && (S / (2 *c + 1) - 1) % 2 == 0){
        int d = (S / (2 *c + 1) - 1) / 2;
        if(d > b) ans += get(c, d);
      }
      if((S - area) % (2 * (c - a)) == 0){
        int d = (S - area) / (2 * (c - a));
        if(d % 2){
          d = (d - 1) / 2;
          if(d <= b) ans += get(c, b);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}