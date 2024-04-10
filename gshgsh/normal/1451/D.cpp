#include<iostream>
using namespace std;
int T,N,K;int main(){cin>>T;while(T--){cin>>N>>K;int l=0;while(2ll*K*(l+1)*K*(l+1)<=1ll*N*N)l++;cout<<(1ll*K*l*K*l+1ll*K*(l+1)*K*(l+1)<=1ll*N*N?"Ashish\n":"Utkarsh\n");}return 0;}