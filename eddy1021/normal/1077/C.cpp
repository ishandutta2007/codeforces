#include <bits/stdc++.h>
using namespace std;
const int N=202020;
typedef long long LL;
LL n, a[N];
int main(){
  cin>>n;
  for(int i=0; i<n; i++)
    cin>>a[i];
  LL sum=accumulate(a, a+n, 0LL);
  int who=max_element(a, a+n)-a;
  vector<int> ans;
  for(int i=0; i<n; i++){
    LL mx=a[who];
    if(i == who){
      mx=0;
      for(int j=0; j<n; j++)
        if(j != who)
          mx=max(mx, a[j]);
    }
    if(mx+mx == sum-a[i])
      ans.push_back(i+1);
  }
  printf("%d\n", (int)ans.size());
  for(size_t i=0; i<ans.size(); i++)
    printf("%d%c", ans[i], " \n"[i+1==ans.size()]);
}