#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N;string a,b;int main(){cin>>T;while(T--){int c1=0,c2=0;cin>>N>>a>>b;For(i,0,N-1)c1+=a[i]<b[i],c2+=a[i]>b[i];cout<<(c1<=c2?c1<c2?"RED\n":"EQUAL\n":"BLUE\n");}return 0;}