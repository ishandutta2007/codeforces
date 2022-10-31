#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1111;
int n, a[N];
vector<int> ans;
int main(){
  cin>>n;
  for(int i=0; i<n; i++)
    cin>>a[i];
  for(int i=0; i<n; i++)
    if(i+1==n or a[i+1]==1)
      ans.push_back(a[i]);
  printf("%d\n", (int)ans.size());
  for(auto x: ans)
    printf("%d ", x);
  puts("");
}