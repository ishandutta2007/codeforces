#include<iostream>
using namespace std;
int T,a,b;int main(){cin>>T;while(T--){cin>>a>>b;if(b==1){cout<<"NO\n";continue;}cout<<"YES\n";cout<<1ll*a*b<<' '<<a<<' '<<1ll*a*(b+1)<<endl;}return 0;}