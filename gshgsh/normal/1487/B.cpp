#include<iostream>
using namespace std;
int T,N,K;
int main(){cin>>T;while(T--){cin>>N>>K;if(N&1)cout<<((K-1)/(N/2)*(N/2+1)+(K-1)%(N/2))%N+1<<endl;else cout<<(K-1)%N+1<<endl;}return 0;}