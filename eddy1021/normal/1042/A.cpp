#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=111;
int a[N], n, m;
int cal(){
  sort(a, a+n);
  while(m--){
    int id=min_element(a, a+n)-a;
    a[id]++;
  }
  return *max_element(a, a+n);
}
int main(){
  cin>>n>>m;
  for(int i=0; i<n; i++)
    cin>>a[i];
  int mx=*max_element(a, a+n);
  mx+=m;
  cout<<cal()<<" "<<mx<<endl;
}