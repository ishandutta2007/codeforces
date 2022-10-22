#include<iostream>
#include<cstdio>
using namespace std;
int T,N,M,x,y;int main(){cin>>T;while(T--)cin>>N>>M>>x>>y,cout<<max(x-1,N-x)+max(y-1,M-y)<<endl;return 0;}