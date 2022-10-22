#include<iostream>
using namespace std;
int T,N;int main(){cin>>T;while(T--){cin>>N;while(N>=2020){if(N%2021==0)break;N-=2020;}cout<<(N%2021==0?"YES\n":"NO\n");}return 0;}