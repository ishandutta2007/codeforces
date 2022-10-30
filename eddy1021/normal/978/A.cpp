#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n;
bool o[1021];
int main(){
  cin>>n;
  v.resize(n);
  for(int i=0; i<n; i++)
    cin>>v[i];
  vector<int> ans;
  reverse(v.begin(), v.end());
  for(int x: v){
    if(o[x]) continue;
    o[x]=true;
    ans.push_back(x);
  }
  reverse(ans.begin(), ans.end());
  printf("%d\n", (int)ans.size());
  for(size_t i=0; i<ans.size(); i++)
    printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
}