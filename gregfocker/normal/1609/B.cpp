#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll


signed main(){
  ios::sync_with_stdio(0); cin.tie(0);


  int n,q;
  string s;
  cin>>n>>q>>s;


  int sol=0;
  for (int i=0;i+2<n;i++){
    sol+=(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c');
  }


  function<void(int,int)>upd=[&](int i,int val){

    if (0<=i&&i+2<n&&s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')sol+=val;
  };


  while (q--){
    int i;
    string t;
    cin>>i>>t;
    i--;
    for (int j=i-3;j<=i+3;j++)upd(j,-1);
    s[i]=t[0];
    for (int j=i-3;j<=i+3;j++)upd(j,+1);
    cout<<sol<<"\n";

  }

  return 0;
}