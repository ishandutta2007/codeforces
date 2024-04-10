#include<iostream>
#include<string>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int main(){int T;cin>>T;while(T--){string a;cin>>a;int N=a.length();if(N&1){cout<<"NO\n";continue;}cout<<(a[0]!=')'&&a[N-1]!='('?"YES\n":"NO\n");}return 0;}