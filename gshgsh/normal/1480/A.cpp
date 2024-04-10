#include<iostream>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T;int main(){cin>>T;while(T--){string s;cin>>s;int N=s.length();For(i,0,N-1)if(i+1&1)s[i]=s[i]=='a'?'b':'a';else s[i]=s[i]=='z'?'y':'z';cout<<s<<endl;}return 0;}