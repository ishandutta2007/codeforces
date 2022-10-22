#include<iostream>
#include<cstdio>
using namespace std;
int T,N;int main(){cin>>T;while(T--)cin>>N,cout<<(N>3?2+(N&1):N-1)<<endl;return 0;}