#include<iostream>
using namespace std;
int T,N;int main(){cin>>T;while(T--){cin>>N;if(N==1||N==2||N==4){cout<<-1<<endl;continue;}if(N%3==0)cout<<N/3<<" 0 0\n";else if(N%3==1)cout<<N/3-2<<" 0 1\n";else cout<<N/3-1<<" 1 0\n";}return 0;}