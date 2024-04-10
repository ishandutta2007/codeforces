#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N,a,b;int main(){cin>>T;while(T--){cin>>N;For(i,1,N/2)cin>>a>>b,cout<<b<<' '<<-a<<endl;}return 0;}