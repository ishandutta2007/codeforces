#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, d, k;
vector<pair<int,int>>ans;
void no(){
  puts("NO");
  exit(0);
}
void yes(){
  puts("YES");
  for(auto p: ans)
    printf("%d %d\n", p.first, p.second);
}
int main(){
  scanf("%d%d%d", &n, &d, &k);
  if(d>n-1) no();
  if(n==1) yes();
  if(d>1 and k<2) no();
  for(int i=1; i<=d; i++)
    ans.push_back({i, i+1});
  vector< tuple<int,int,int> > cand;
  for(int i=1; i<=d+1; i++)
    cand.push_back(make_tuple(i, k-(i==1 or i==d+1 ? 1:2), min(i-1, d+1-i)));
  for(int i=d+2; i<=n; i++){
    while(cand.size() and
          (get<1>(cand.back())<=0 or
           get<2>(cand.back())<=0))
      cand.pop_back();
    if(cand.empty()) no();
    ans.push_back({i, get<0>(cand.back())});
    get<1>(cand.back())--;
    cand.push_back(make_tuple(i, k-1, get<2>(cand.back())-1));
  }
  yes();
}