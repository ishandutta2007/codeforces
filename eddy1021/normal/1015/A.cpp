#include <bits/stdc++.h>
using namespace std;
const int N=111;
int a[N];
int main(){
  int n, m;
  cin>>n>>m;
  while(n--){
    int li, ri;
    cin>>li>>ri;
    for(int i=li; i<=ri; i++) a[i]=1;
  }
  vector<int> ans;
  for(int i=1; i<=m; i++)
    if(!a[i])
      ans.push_back(i);
  cout<<ans.size()<<endl;
  for(auto i: ans) cout<<i<<" ";
  cout<<endl;
}