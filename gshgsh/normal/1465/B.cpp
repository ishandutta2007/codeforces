#include<iostream>
using namespace std;
#define ll long long
int T;ll N;int main(){cin>>T;while(T--){cin>>N;while(1){bool flag=1;ll x=N;while(x)x%10?flag&=N%(x%10)==0:0,x/=10;if(flag){cout<<N<<endl;break;}N++;}}return 0;}