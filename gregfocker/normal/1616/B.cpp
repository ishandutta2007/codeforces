#include <bits/stdc++.h>

using namespace std;



int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int t;
  cin>>t;
  while (t--)
  {
    int n;
    string s;
    cin>>n>>s;
    if(n==1){
      cout<<s[0]<<s[0]<<"\n";
      continue;
    }
    if(s[0]==s[1]){
      cout<<s[0]<<s[0]<<"\n";
      continue;
    }
    string sol;
    for (int i=0;i+1<n;i++){
      if(s[i+1]>s[i]){
        for (int j=0;j<=i;j++)sol+=s[j];
        for (int j=i;j>=0;j--)sol+=s[j];
        break;
      }
    }
    if(sol.empty()){
      sol=s;
      reverse(s.begin(),s.end());
      sol+=s;
    }
    cout<<sol<<"\n";
  }
}