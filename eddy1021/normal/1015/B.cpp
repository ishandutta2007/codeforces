#include <bits/stdc++.h>
using namespace std;
int n;
char s[55], t[55];
int main(){
  cin>>n>>s>>t;
  vector<int> ans;
  for(int i=0; i<n; i++){
    if(s[i] == t[i]) continue;
    for(int j=i; j<n; j++)
      if(s[j] == t[i]){
        for(int k=j-1; k>=i; k--){
          ans.push_back(k+1);
          swap(s[k], s[k+1]);
        }
        break;
      }
    if(s[i] != t[i]){
      puts("-1");
      exit(0);
    }
  }
  cout<<ans.size()<<endl;
  for(auto i: ans) cout<<i<<" ";
  cout<<endl;
}