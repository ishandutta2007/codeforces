#include<iostream>
using namespace std;
int T,x,y,k;int main(){cin>>T;while(T--)cin>>x>>y>>k,cout<<(1ll*k*y+k-1+x-2)/(x-1)+k<<endl;return 0;}