#include <bits/stdc++.h>
using namespace std;
const int N=101010;
int n, x, a[N];
bool g(){
  sort(a, a+n);
  return unique(a, a+n)-a < n;
}
void A(int b){
  cout<<b<<endl;
  exit(0);
}
int main(){
  cin>>n>>x;
  for(int i=0; i<n; i++) cin>>a[i];
  if(g()) A(0);
  for(int i=0; i<n; i++)
    if((a[i] & x) != a[i] and
       *lower_bound(a, a+n, a[i]&x) == (a[i]&x))
      A(1);
  for(int i=0; i<n; i++) a[i]&=x;
  if(g()) A(2);
  A(-1);
}