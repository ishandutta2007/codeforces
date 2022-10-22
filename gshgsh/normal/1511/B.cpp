#include<iostream>
using namespace std;
int T,a,b,c;int getcnt(int x){int cnt=0;while(x)cnt++,x/=10;return cnt;}
int main(){cin>>T;while(T--){cin>>a>>b>>c;int x=1;while(getcnt(x)<c)x*=10;int y=x,z=x;while(getcnt(y)<a)y*=2;while(getcnt(z)<b)z*=3;cout<<y<<' '<<z<<endl;}return 0;}