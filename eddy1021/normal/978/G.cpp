#include <bits/stdc++.h>
using namespace std;
const int N = 111;
int n, m, who[N], s[N], d[N], c[N], ans[N];
void no(){
  puts("-1");
  exit(0);
}
int main(){
  scanf("%d%d", &n, &m);
  for(int i=1; i<=m; i++){
    scanf("%d%d%d", &s[i], &d[i], &c[i]);
    who[d[i]]=i;
  }
  vector<int> can;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++)
      if(s[j] == i)
        can.push_back(j);
    if(who[i]){
      if(c[who[i]]) no();
      ans[i]=m+1;
      continue;
    }
    if(can.empty()) continue;
    sort(can.begin(), can.end(),
         [&](int i1, int i2){
           return d[i1] > d[i2];
         });
    while(can.size() and c[can.back()] == 0)
      can.pop_back();
    if(can.empty()) continue;
    c[can.back()]--;
    ans[i]=can.back();
  }
  for(int i=1; i<=n; i++)
    printf("%d%c", ans[i], " \n"[i == n]);
}