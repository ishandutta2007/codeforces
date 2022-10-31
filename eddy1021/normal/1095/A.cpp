#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  string s;
  cin>>n>>s;
  for(int i=0, d=1; i<n; i+=d, d+=1)
    cout<<s[i];
  cout<<endl;
}