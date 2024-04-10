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
#define MAXN 111111
#define LL long long

using namespace std;

int N,a[MAXN];
vector<int> n[MAXN];
stack<int> s,f;
LL g[MAXN];

LL get(int start){
  int Start=start,father;
  int i,S;
  bool ok;
  vector< LL > pos;
  s.push(start);
  f.push(-1);
  while(!s.empty()){
    start=s.top();
    father=f.top();
    S=n[start].size();
    LL disp=0,sum=0;
    ok=true;
    FOR(i,S){
      if(n[start][i]==father) continue;
      if(g[n[start][i]]==-1){
        a[n[start][i]]--;
        s.push(n[start][i]);
        f.push(start);
        ok=false;
      }
    }
    if(!ok) continue;
    pos.clear();
    FOR(i,S){
      if(n[start][i]==father) continue;
      pos.push_back(g[n[start][i]]);
      disp+=a[n[start][i]];
    }
    sort(pos.begin(), pos.end());
    for(i=pos.size()-1; i>=0; i--){
      if(a[start]==0) break;
      sum+=pos[i]+2;
      a[start]--;
    }
    sum+=2*min((LL)a[start],disp);
    a[start]-=(min((LL)a[start],disp));
    s.pop(); f.pop();
    g[start]=sum;
    //printf("start:%d father:%d sum:%lld disp:%lld a[start]:%d\n",start+1,father+1,sum,disp,a[start]);
  }
  return g[Start];
}

int main(int argc, char *argv[]){
  int i,A,B;
  scanf("%d",&N);
  FOR(i,N) scanf("%d",a+i);
  FOR(i,N-1){
    scanf("%d%d",&A,&B);
    A--; B--;
    n[A].push_back(B);
    n[B].push_back(A);
  }
  FOR(i,N+1) g[i]=-1;
  scanf("%d",&A);
  printf("%I64d\n",get(A-1));
  return 0;
}