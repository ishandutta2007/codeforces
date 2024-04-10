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

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

int changes(int a, int b, int N){
  int n = 0, ans = 0;
  while(a){ // a < b
    n += b / a;
    ans += max(0, b / a - 1);
    b %= a;
    swap(a, b);
  }
  if(n != N || b > 1) return 1111111;
  return ans;
}

int main(int argc, char *argv[]){
  int N, R, best, bestlast;
  scanf("%d%d", &N, &R);
  best = R + 1; bestlast = -1;
  FOR(last, 1, R){
    int tmp = changes(last, R, N);
    if(tmp < best){
      //printf("last: %d best: %d R: %d\n", last, tmp, R);
      best = tmp;
      bestlast = last;
    }
  }
  if(N == 1 && R == 1){ printf("0\nT\n"); return 0; }
  if(bestlast == -1) printf("IMPOSSIBLE\n");
  else{
    string ans;
    best--;
    while(bestlast && R){
      if(bestlast == 1 && R == 1){
        if(ans[ans.size() - 1] == 'B') ans.push_back('T');
        else ans.push_back('B');
        break;
      }
      if(bestlast < R){ ans.push_back('B'); R -= bestlast; }
      else{ ans.push_back('T'); bestlast -= R; }
    }
    reverse(ans.begin(), ans.end());
    if(ans[0] == 'B') REP(i, N) {
      if(ans[i] == 'B') ans[i] = 'T';
      else ans[i] = 'B';
    }
    printf("%d\n", best);
    printf("%s\n", ans.c_str());
  }
  return 0;
}