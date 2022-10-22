#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define LCM 720720
int N,M;int main(){cin>>N>>M;int x;For(i,1,N)For(j,1,M)cin>>x,cout<<LCM+(i+j&1)*x*x*x*x<<(j==M?'\n':' ');return 0;}