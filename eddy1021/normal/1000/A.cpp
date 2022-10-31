#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
map<string,int> M;
const int N=111;
string s[N];
int main(){
  cin>>n;
  int ans=0;
  for(int i=0; i<n; i++){
    cin>>s[i];
    M[s[i]]++;
  }
  for(int i=0; i<n; i++)
    cin>>s[i];
  for(int i=0; i<n; i++)
    if(M[s[i]]==0)
      ans++;
    else
      M[s[i]]--;
  cout<<ans<<endl;
}