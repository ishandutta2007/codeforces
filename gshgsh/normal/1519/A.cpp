#include<iostream>
using namespace std;
int T,a,b,c;int main(){cin>>T;while(T--){cin>>a>>b>>c;if(a>b)swap(a,b);cout<<(b<=1ll*a*(1+c)?"YES\n":"NO\n");}return 0;}