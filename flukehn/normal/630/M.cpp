#include<bits/stdc++.h>
using namespace std;

int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	long long x;
  while(cin>>x){
    x=(x%360+360+44)%360;
    cout<<(x%359)/90<<"\n";
  }
}