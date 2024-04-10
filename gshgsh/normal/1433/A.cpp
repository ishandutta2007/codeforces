#include<iostream>
using namespace std;
int T,a;int main(){cin>>T;while(T--){cin>>a;int ans=(a%10-1)*10;int cnt=0;while(a)a/=10,ans+=++cnt;cout<<ans<<endl;}return 0;}