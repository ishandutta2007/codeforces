#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1021;
int n, m, q, ans[N];
string s, t;
int main(){
  scanf("%d%d%d", &n, &m, &q);
  cin>>s>>t;
  for(int i=0; i+m<=n; i++)
    if(s.substr(i, m) == t)
      ans[i+1]++;
  for(int i=2; i<=n; i++)
    ans[i]+=ans[i-1];
  while(q--){
    int li, ri;
    scanf("%d%d", &li, &ri);
    ri=ri-m+1;
    printf("%d\n", max(0, ans[max(0,ri)]-ans[li-1]));
  }
}