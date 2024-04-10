#include <bits/stdc++.h>
using namespace std;
const int N=202020;
int n, a[N];
int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++) scanf("%d", &a[i]);
  unordered_map<int, int> cnt;
  for(int i=1; i<=n; i++) cnt[a[i]]++;
  int mst=-1, who=0;
  for(auto i: cnt)
    if(i.second > mst)
      tie(who, mst)=i;
  vector<tuple<int, int, int>> ans;
  bool fst=false;
  for(int i=1; i<=n; i++){
    if(a[i] != who) continue;
    if(not fst){
      for(int j=i-1; j>=1; j--)
        if(a[j] > a[i])
          ans.push_back(make_tuple(2, j, j+1));
        else
          ans.push_back(make_tuple(1, j, j+1));
      fst=true;
    }
    for(int j=i+1; j<=n; j++){
      if(a[i] == a[j]) break;
      if(a[j] > a[i])
        ans.push_back(make_tuple(2, j, j-1));
      else
        ans.push_back(make_tuple(1, j, j-1));
    }
  }
  printf("%d\n", (int)ans.size());
  for(auto p: ans)
    printf("%d %d %d\n",
           get<0>(p),
           get<1>(p),
           get<2>(p));
}