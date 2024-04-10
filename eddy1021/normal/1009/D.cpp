// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=101010;
int n, m;
vector<pair<int,int>> ans;
void no(){
  puts("Impossible");
  exit(0);
}
int main(){
  scanf("%d%d", &n, &m);
  if(m<n-1) no();
  for(int i=2; i<=n; i++)
    ans.push_back({1, i});
  m-=n-1;
  for(int i=2; i<=n and m>0; i++)
    for(int j=i+1; j<=n and m>0; j++)
      if(__gcd(i, j) == 1){
        ans.push_back({i, j});
        m--;
      }
  if(m!=0) no();
  puts("Possible");
  for(auto e: ans)
    printf("%d %d\n", e.first, e.second);
}