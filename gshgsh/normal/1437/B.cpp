#include<iostream>
#include<string>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N;string a;int main(){cin>>T;while(T--){cin>>N>>a;int ans0=0,ans1=0;For(i,1,N-1)ans0+=a[i]=='0'&&a[i]==a[i-1],ans1+=a[i]=='1'&&a[i]==a[i-1];cout<<max(ans0,ans1)<<endl;}return 0;}