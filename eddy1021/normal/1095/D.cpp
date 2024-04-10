#include <bits/stdc++.h>
using namespace std;
const int N=202020;
int n, a[N][2];
bool used[N];
int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
    for(int j=0; j<2; j++)
      scanf("%d", &a[i][j]);
  auto has=[&](int x, int y){
    return a[x][0]==y or a[x][1]==y;
  };
  vector<int> ans;
  ans.push_back(1);
  used[1]=true;
  for(int _=1; _<n; _++){
    assert((int)ans.size() == _);
    int lst=ans.back();
    for(int i=0; i<2; i++){
      int cand=a[lst][i];
      int other=a[lst][1-i];
      if(used[cand]) continue;
      if(has(cand, other)){
        used[cand]=true;
        ans.push_back(cand);
        break;
      }
    }
  }
  for(int i=0; i<n; i++)
    printf("%d%c", ans[i], " \n"[i+1==n]);
}