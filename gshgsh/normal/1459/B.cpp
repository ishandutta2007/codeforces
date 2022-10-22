#include<iostream>
#include<cstdio>
using namespace std;
int main(){int N;cin>>N;cout<<(N&1?(N/2+1)*(N/2+2)*2:(N/2+1)*(N/2+1))<<endl;return 0;}