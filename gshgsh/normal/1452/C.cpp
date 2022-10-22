#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int T,N,tot[2],ans;string a;
int main(){cin>>T;while(T--){cin>>a;N=a.length();ans=0;tot[0]=tot[1]=0;For(i,0,N-1)if(a[i]=='('||a[i]=='[')tot[a[i]=='(']++;else if(tot[a[i]==')'])tot[a[i]==')']--,ans++;cout<<ans<<endl;}return 0;}