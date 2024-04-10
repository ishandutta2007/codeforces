#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int main(){
  long long C,Hr,Hb,Wr,Wb;
  cin>>C>>Hr>>Hb>>Wr>>Wb;
  if(Wr<Wb){
    swap(Wr,Wb);
    swap(Hr,Hb);
  }
  long long prod=(long long)Wr*Wb;
  long long whole=max(0LL,C-2*prod)/prod;
  long long left=C-whole*prod;
  long long ans=0;
  for(long long Cr=0;Cr*Wr<=left;Cr++){
    long long take=(left-Cr*Wr)/Wb;
    long long gain=Cr*Hr+take*Hb;
    gain+=max(whole*Wb*Hr,whole*Wr*Hb);
    ans=max(ans,gain);
  }
  cout<<ans<<endl;
  return 0;
}