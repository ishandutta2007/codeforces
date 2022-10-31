#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2020;
int n, k, a[N];
int main(){
  scanf("%d%d", &n, &k);
  for(int i=0; i<n; i++) scanf("%d", &a[i]);
  vector<pair<int,int>> v;
  for(int i=0; i<n; i++) v.push_back({a[i], i});
  sort(v.begin(), v.end());
  vector<int> cand;
  int ans=0;
  while(k--){
    ans+=v.back().first;
    cand.push_back(v.back().second);
    v.pop_back();
  }
  printf("%d\n", ans);
  sort(cand.begin(), cand.end());
  for(size_t i=0; i<cand.size(); i++){
    ans=1;
    if(i==0) ans+=cand[i]-0;
    if(i+1==cand.size()) ans+=n-1-cand[i];
    if(i) ans+=cand[i]-cand[i-1]-1;
    printf("%d%c", ans, " \n"[i+1==cand.size()]);
  }
}