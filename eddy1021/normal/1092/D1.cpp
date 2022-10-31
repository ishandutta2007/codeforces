#include <bits/stdc++.h>
using namespace std;
const int N=202020;
int n, a[N];
int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++) scanf("%d", &a[i]);
  for(int i=1; i<=n; i++) a[i]&=1;
  vector<int> stk;
  for(int i=1; i<=n; i++)
    if(stk.empty() or stk.back() != a[i])
      stk.push_back(a[i]);
    else
      stk.pop_back();
  puts(stk.size()<=1u?"YES":"NO");
}