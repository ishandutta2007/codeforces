#include<iostream>
#include<string>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T;string a,b;int GCD(int a,int b){return b?GCD(b,a%b):a;}
int main(){cin>>T;while(T--){cin>>a>>b;int N=a.length(),M=b.length(),x=N*M/GCD(N,M);string c="",d="";For(i,1,x/N)c=c+a;For(i,1,x/M)d=d+b;cout<<(c==d?c:"-1")<<endl;}return 0;}