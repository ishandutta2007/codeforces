#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, a[111];
int main(){
  cin>>n;
  while(n --){
    int x; cin>>x;
    a[x]++;
  }
  cout<<*max_element(a,a+111)<<endl;
}